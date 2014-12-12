#include "IA.hpp"

ia::ia(Player *p): _player(p)
{
  this->_istarget = false;
}

ia::~ia()
{
}

e_object	ia::getObj(e_direction dir)
{
  AObject *		tt;
  std::pair<int,int>	tmp;

  tmp = this->_player->getPos();
  switch (dir)
    {
    case LEFT:{
      tmp.first -= 1;
      break;
    }
    case DOWN:{
      tmp.second += 1;
      break;
    }
    case UP:{
      tmp.second -= 1;
      break;
    }
    case RIGHT:{
      tmp.first += 1;
      break;
    }
    case STAY:{
      tmp.first = tmp.first;
      break;
    }
    }
  tt = (this->_player->getManager())->getObjByPos(tmp);
  if (tt == NULL)
    return NOTHING;
  return tt->getType();
}

bool	ia::check(e_object obj)
{
  if (obj == this->getObj(LEFT) || obj == this->getObj(RIGHT) || obj == this->getObj(UP) || obj == this->getObj(DOWN) || obj == this->getObj(STAY))
    return true;
  return false;
}

bool	ia::isOnTarget()
{
  if (this->_target.first == static_cast<int>(this->_player->getPos().first) && this->_target.second == static_cast<int>(this->_player->getPos().second))
    return true;
  return false;
}

void	ia::run()
{
  this->_target = this->_player->getManager()->getPosPlayer(this->_player->getPos());
  if ((this->check(BOX) == true || this->check(PLAYER) == true || this->isOnTarget() == true) && this->getObj(STAY) != BOMB)
      this->_player->PutBombe();
    this->move();
}

void	ia::move()
{
  if (this->_target.first < this->_player->getPos().first && BOX != this->getObj(LEFT) && WALL != this->getObj(LEFT))
    this->_player->left(this->_player->getManager()->getClock());
  else if (this->_target.first > this->_player->getPos().first && BOX != this->getObj(RIGHT) && WALL != this->getObj(RIGHT))
    this->_player->right(this->_player->getManager()->getClock());
  else if (this->_target.second < this->_player->getPos().second && BOX != this->getObj(UP) && WALL != this->getObj(UP))
    this->_player->up(this->_player->getManager()->getClock());
  else if (this->_target.second > this->_player->getPos().second && BOX != this->getObj(DOWN) && WALL != this->getObj(DOWN))
    this->_player->down(this->_player->getManager()->getClock());
}
