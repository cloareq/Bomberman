//
// Player.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Mon May 12 10:27:19 2014 Antoine BERGHEN
// Last update Sun Jun 15 23:32:42 2014 lebeau_c
//

#include "Player.hpp"

Player::Player(std::pair<int, int> pos, std::string name, float size, int lvl, GameEngine *ge) : AObject(pos, name, size, PLAYER), _ge(ge)
{
  this->_score = 0;
  this->_speed = 4;
  this->_Life = 1;
  this->_Lvl = lvl;
  this->_nbBombes = 1;
  this->init();
  this->setPositions();
  this->_down = 1;
  this->_t = clock();
  this->_VRight = 0;
  this->_VUp = 0;
  this->_pp1 = (Pp1*)_ge->getObj()[6];
  this->_pp2 = (Pp2*)_ge->getObj()[7];
  this->_death = false;
}

bool	Player::init()
{
  if (_model.load("./assets/marvin.fbx") == -1)
  {
    std::cout << "error load marvin.fbx" << std::endl;
    return (false);
  }
  if (_model.createSubAnim(0, "run", 36, 53) ==false)
  {
    std::cout << "error subanim marvin.fbx" << std::endl;
    return (false);
  }
  _model.setCurrentAnim(1);
  return (true);
}

void	Player::PutBombe()
{
   float x(_position.x);
   float y(_position.z);

   if (_nbBombes == 0)
     return;
   _nbBombes -= 1;
   if (x - 0.5 > (int)x)
      x += (int)1;
   if (y - 0.5 > (int)y)
      y += (int)1;
    AObject *bombe = new Bomb(std::make_pair(x, y), "Bomb", 0.0025, 1, 3, clock());
   _bombes.push_back(bombe);
 }

void Player::drawFire(int x, int y, clock_t t)
{
  _t = t;
  _fx = x;
  _fy = y;
  _ge->getObj()[3]->_lpos.push_back(std::make_pair(x, y));
  if (burn_wall(x+1, y, _ge) != true)
    _ge->getObj()[3]->_lpos.push_back(std::make_pair(x+1, y));
  if (burn_wall(x, y-1, _ge) != true)
    _ge->getObj()[3]->_lpos.push_back(std::make_pair(x, y-1));
  if (burn_wall(x, y+1, _ge) != true)
    _ge->getObj()[3]->_lpos.push_back(std::make_pair(x, y+1));
  if (burn_wall(x-1, y, _ge) != true)
    _ge->getObj()[3]->_lpos.push_back(std::make_pair(x-1, y));
}

void Player::Died(int x, int y)
{
  if((static_cast<int>(x + 1) == static_cast<int>(_position.x) && static_cast<int>(y) == static_cast<int>(_position.z))
     || (static_cast<int>(x - 1) == static_cast<int>(_position.x) && static_cast<int>(y) == static_cast<int>(_position.z))
     || (static_cast<int>(x) == static_cast<int>(_position.x) && static_cast<int>(y + 1) == static_cast<int>(_position.z))
     || (static_cast<int>(x) == static_cast<int>(_position.x) && static_cast<int>(y - 1) == static_cast<int>(_position.z))
     || (static_cast<int>(x) == static_cast<int>(_position.x) && static_cast<int>(y) == static_cast<int>(_position.z)))
    _Life -= 1;
  if (_Life < 1)
    _death = true;
}

void	Player::ChangeSpeed(int speed)
{
   this->_speed = speed;
  return ;
}


void	Player::print_position()
{
   std::cout << "X:" << _position.x << " Y:" << _position.z << std::cout;
}

void	Player::update(gdl::Clock const &clock, gdl::Input &input)
{
   if (_Lvl == 1)
      update_p1(clock, input);
   else if (_Lvl == 2)
      update_p2(clock, input);
   if (checkBonus(_ge->getObj()[4]) == true)
      _Life++;
   if (checkBonus(_ge->getObj()[5]) == true)
      _speed = VIT * 1.5;
}

bool	Player::checkBonus(AObject *bonus)
{
   for (size_t j = 0; j < bonus->_lpos.size(); ++j)
   {
      float x(_position.x);
      float y(_position.z);
      if (x - 0.5 > (int)x)
        x += (int)1;
      if (y - 0.5 > (int)y)
        y += (int)1;
      if (((int)bonus->_lpos[j].first == (int)x) && ((int)bonus->_lpos[j].second == (int)y) )
      {
        bonus->_lpos.erase(bonus->_lpos.begin() + j);
        return (true);
      }
   }
   return (false);
}

void	Player::setPositions()
{
   _right = 0;
   _left = 0;
   _up = 0;
   _down = 0;
}

void Player::up(gdl::Clock const &clock)
{
   rotate(glm::vec3(0, 1, 0), 180);
   if ((_position.z - static_cast<float>(clock.getElapsed() * (_speed * 2))) < 1.0)
      return;
   if(CheckColision(_position.x, (_position.z - static_cast<float>(clock.getElapsed() * (_speed * 2)))) == true)
    {
       translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed() * _speed));
       _position.z -= (static_cast<float>(clock.getElapsed() * _speed));
       setPos(getPos().first, _position.z);
       if (_up != 1)
	{
	  setPositions();
	  _up = 1;
	}
    }
  else
    setPositions();
}

void Player::down(gdl::Clock const &clock)
{
  if (this->_VRight == 1)
      this->_VRight = 0;
  rotate(glm::vec3(0, 1, 0), 1);
  if(CheckColision(_position.x, (_position.z + static_cast<float>(clock.getElapsed() * (_speed * 2)))) == true)
    {
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed() * _speed));
       _position.z += (static_cast<float>(clock.getElapsed() * _speed));
       setPos(getPos().first, _position.z);
      if (_down != 1)
	{
	  setPositions();
	  _down = 1;
	}
    }
  else
    setPositions();
}

void Player::right(gdl::Clock const & clock)
{
  rotate(glm::vec3(0, 1, 0), 90);
  if(CheckColision((_position.x + static_cast<float>(clock.getElapsed() * (_speed * 2))), (_position.z)) == true)
    {
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed() * _speed));
     _position.x += (static_cast<float>(clock.getElapsed() * _speed));
     setPos(_position.x, getPos().second);
      if (_right != 1)
	{
	  setPositions();
	  _right = 1;
	}
    }
  else
    {
      setPositions();
      this->_VRight = 1;
    }
}

void	Player::left(gdl::Clock const & clock)
{
  rotate(glm::vec3(0, 1, 0), -90);
  if ((_position.x - static_cast<float>(clock.getElapsed() * (_speed * 2))) < 1.0)
     return;
  if(CheckColision((_position.x - static_cast<float>(clock.getElapsed() * (_speed * 2))), _position.z) == true)
    {
     translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed() * _speed));
     _position.x -= (static_cast<float>(clock.getElapsed() * _speed));
     setPos(_position.x, getPos().second);
      if (_left != 1)
	{
	  setPositions();
	  _left = 1;
	}
    }
  else
    setPositions();
}

bool	Player::CheckColision(float x, float y)
{
  if (x - 0.5 > (int)x)
     x += (int)1;
  if (y - 0.5 > (int)y)
     y += (int)1;
  for (size_t i = 0; i < this->_ge->getObj()[0]->_lpos.size(); ++i)
   {
     if(static_cast<int>(x) == this->_ge->getObj()[0]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[0]->_lpos[i].second)
	 return (false);
   }
  for (size_t i = 0; i < this->_ge->getObj()[1]->_lpos.size(); ++i)
   {
     if (static_cast<int>(x) == this->_ge->getObj()[1]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[1]->_lpos[i].second)
	 return (false);
   }
   return (true);
}

void	Player::update_p1(gdl::Clock const &clock, gdl::Input &input)
{
   static int i;
   if (input.getKey(SDLK_UP) || input.getKey(SDLK_DOWN) || input.getKey(SDLK_LEFT) || input.getKey(SDLK_RIGHT))
   {
      if (i == 0)
	 _model.setCurrentSubAnim("run");
      i++;
   }
   else
   {
      i = 0;
      _model.setCurrentAnim(0);
   }
   if (input.getKey(SDLK_UP))
      this->up(clock);
   if (input.getKey(SDLK_DOWN))
      this->down(clock);
   if (input.getKey(SDLK_LEFT))
      this->left(clock);
   if (input.getKey(SDLK_RIGHT))
      this->right(clock);
   if (input.getKey(SDLK_SPACE) && _nbBombes > 0)
   {
    std::cout << _nbBombes << std::endl;
    this->PutBombe();
    if (_nbBombes < 0)
      _nbBombes = 0;
   }
   if (_pp1->_lpos.size() > 0)
     _pp1->_lpos.pop_back();
   _pp1->_lpos.push_back(std::make_pair(_position.x, _position.z));
}

void	Player::update_p2(gdl::Clock const &clock, gdl::Input &input)
{
   static int i;
   if (input.getKey(SDLK_z) || input.getKey(SDLK_s) || input.getKey(SDLK_q) || input.getKey(SDLK_d))
   {
      if (i == 0)
	 _model.setCurrentSubAnim("run");
      i++;
   }
   else
   {
      i = 0;
      _model.setCurrentAnim(0);
   }
   if (input.getKey(SDLK_z))
      this->up(clock);
   if (input.getKey(SDLK_s))
      this->down(clock);
   if (input.getKey(SDLK_q))
      this->left(clock);
   if (input.getKey(SDLK_d))
      this->right(clock);
   if (input.getKey(SDLK_LCTRL) && _nbBombes > 0)
   {
    std::cout << _nbBombes << std::endl;
      this->PutBombe();
      _nbBombes -= 1;
      if (_nbBombes < 0)
        _nbBombes = 0;
   }
   if (_pp2->_lpos.size() > 0)
      _pp2->_lpos.pop_back();
   _pp2->_lpos.push_back(std::make_pair(_position.x, _position.z));
 }

void Player::check_fire()
{
  if ((((float)clock() - (float)_t)/CLOCKS_PER_SEC) > 1)
    erase_fire(_fx, _fy);
}
void	Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  check_fire();
   _model.draw(shader, getTransformation(), clock.getElapsed());
}

void	Player::erase_fire(int x, int y)
{
  for (size_t i = 0; i < this->_ge->getObj()[3]->_lpos.size(); ++i)
  {
    if((static_cast<int>(x) == this->_ge->getObj()[3]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[3]->_lpos[i].second)
      || (static_cast<int>(x + 1) == this->_ge->getObj()[3]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[3]->_lpos[i].second)
     || (static_cast<int>(x - 1) == this->_ge->getObj()[3]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[3]->_lpos[i].second)
     || (static_cast<int>(x) == this->_ge->getObj()[3]->_lpos[i].first && static_cast<int>(y + 1) == this->_ge->getObj()[3]->_lpos[i].second)
   || (static_cast<int>(x) == this->_ge->getObj()[3]->_lpos[i].first && static_cast<int>(y - 1) == this->_ge->getObj()[3]->_lpos[i].second))
    {
      this->_ge->getObj()[3]->_lpos.erase(this->_ge->getObj()[3]->_lpos.begin() + (i));
      i--;
     }
   }
}

void	Player::drawBombe(gdl::AShader &shader, gdl::Clock const &Clock)
{
  int x = 0;
  int y = 0;
   for (size_t i = 0; i < _bombes.size(); ++i)
   {
      if (((Bomb *)_bombes[i])->getDestruction() == true)
      {
        x = _bombes[i]->getPos().first;
        y = _bombes[i]->getPos().second;
        _bombes.erase(_bombes.begin());
        _nbBombes += 1;
        drawFire(x, y, clock());
        erase_caisse(x, y, _ge);
        Died(x, y);
      }
  _bombes[i]->draw(shader, Clock);
  }
}

bool	Player::burn_wall(int x, int y, GameEngine *ge)
{
  for (size_t i = 0; i < this->_ge->getObj()[0]->_lpos.size(); ++i)
   {
     if(static_cast<int>(x) == this->_ge->getObj()[0]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[0]->_lpos[i].second)
       {
	  return (true);
       }
   }
  return (false);
}

void	Player::erase_caisse(int x, int y, GameEngine *ge)
{
   for (size_t i = 0; i < this->_ge->getObj()[1]->_lpos.size(); ++i)
   {
      if((static_cast<int>(x + 1) == this->_ge->getObj()[1]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[1]->_lpos[i].second)
	 || (static_cast<int>(x - 1) == this->_ge->getObj()[1]->_lpos[i].first && static_cast<int>(y) == this->_ge->getObj()[1]->_lpos[i].second)
	 || (static_cast<int>(x) == this->_ge->getObj()[1]->_lpos[i].first && static_cast<int>(y + 1) == this->_ge->getObj()[1]->_lpos[i].second)
	 || (static_cast<int>(x) == this->_ge->getObj()[1]->_lpos[i].first && static_cast<int>(y - 1) == this->_ge->getObj()[1]->_lpos[i].second))
     {
	this->_ge->getObj()[1]->_lpos.erase(this->_ge->getObj()[1]->_lpos.begin() + (i));
	_score += 50;
	std::cout << "Score: " << _score << "pts" << std::endl;
	i--;
     }
   }
}

void	Player::PickUpBonus(int value)
{
  switch (value) {
  case MoreSpeed:
    this->_InventoryPlayer.push_back(MoreSpeed);
    break;
  case BombMorePowerful:
    this->_InventoryPlayer.push_back(BombMorePowerful);
    break;
  }
}


std::vector<Bonus>	Player::GetInventoryPlayer() const
{
  return (this->_InventoryPlayer);
}

void	Player::SetInventoryPlayer(std::vector<Bonus> inventory)
{
  this->_InventoryPlayer = inventory;
}

GameEngine *     Player::getManager() const
{
  return this->_ge;
}

int	Player::GetScore() const
{
  return (this->_score);
}

void	Player::SetScore(int score)
{
  this->_score += score;
}

size_t	Player::getLife() const
{
  return (this->_Life);
}

void	Player::SetLife(size_t life)
{
  this->_Life += life;
}

int	Player::GetLvl() const
{
  return (this->_Lvl);
}

Player::~Player(){}

bool Player::getDeath() const
{
  return _death;
}

int Player::getlvl() const
{
  return _Lvl;
}
