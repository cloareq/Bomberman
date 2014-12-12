#include <algorithm>
#include <fstream>
#include "IA.hpp"
#include "ParsMap.hpp"
#include "GameEngine.hpp"

GameEngine::GameEngine(Manager *manager)
{
  _map = "maps/" + manager->getMap();
  _nbPlayer = manager->getNBPlayer();
  _nbia = manager->getNBIA();
  _camX = CAM_X;
  _camY = CAM_Y;
  _camZ = CAM_Z;
  _endProgram = false;
}

GameEngine::~GameEngine()
{
    for (size_t i = 0; i <_obj.size(); ++i)
      delete _obj[i];
}

void	GameEngine::loadingScreen()
{
   affPicture(new Loading(std::make_pair(5, 5), "background", 5));
}

void  GameEngine::Loose(int lvl)
{
  clock_t t;

  t = clock();
  if (lvl < 3)
    affPicture(new Ending(std::make_pair(5, 5), "background", 5, 1));
  else
    affPicture(new Ending(std::make_pair(5, 5), "background", 5, 2));
  while ((((float)clock() - (float)t)/CLOCKS_PER_SEC) < 3);
  cleanObj();
  _context.stop();
}

void	GameEngine::affPicture(AObject *tmp)
{
   glm::mat4 projection;
   glm::mat4 transformation;
   glm::mat4 trans;
   projection = glm::perspective(60.0f, (float)SIZE_X / (float)SIZE_Y, 0.1f, 100.0f);
   transformation = glm::lookAt(glm::vec3(CAM_X, CAM_Y, CAM_Z), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
   transformation = glm::translate(transformation, glm::vec3(-5.f, 0.f, -5.f));
   this->_shader.bind();
   this->_shader.setUniform("view", transformation);
   this->_shader.setUniform("projection", projection);
   tmp->rotate(glm::vec3(0,1,0), -90.0);
   tmp->rotate_l(glm::vec3(1,0,0), 90 - 63.4);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   _shader.bind();
   tmp->draw(_shader, _clock);
   _context.flush();
}

bool GameEngine::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;
  glm::mat4 trans;
   if (!_context.start(SIZE_X, SIZE_Y, "My bomberman!"))
   {
      std::cerr << "context.start" << std::endl;
      return false;
   }
   glEnable(GL_DEPTH_TEST);
   glClearColor(0,0,0,0);
   if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
       || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
       || !_shader.build())
      return false;
   loadingScreen();
   glClearColor(.5,.5,.5,0);
   ParsMap test(_map, this->_obj, this);
    _obj.push_back(new Player(std::make_pair(1, 1), "Player", 0.0025, 1, this));
   if (_nbPlayer == 2)
    _obj.push_back(new Player(std::make_pair(3, 3), "Player", 0.0025, 2, this));
   _corecX = (test.getXMap() * -1 / 2);
   _corecZ = test.getYMap() * -1 / 1.7;
   transformation = glm::translate(transformation, glm::vec3(5.f, -2.f, 0.f));
   this->initIa();
   updateCam();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   return true;
}

void		GameEngine::initIa()
{
   int		i =  0;
   Player	*p;

   while (i < this->_nbia)
     {
       p = new Player(std::make_pair(3 + i, 3 + i), "Player", 0.0025, 3 + i, this);
       _obj.push_back(p);
       _lia.push_back(new ia(p));
       i++;
     }
}

void		GameEngine::updateCam()
{
   glm::mat4 transformation;

   transformation = glm::lookAt(glm::vec3(_camX, _camY, _camZ), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
   transformation = glm::translate(transformation, glm::vec3(_corecX, _corecZ, _corecZ));
   _shader.setUniform("view", transformation);
}

void		GameEngine::rotateCam(int x, int y)
{
   static int i;
   static int j;

   i+=x;
   j+=y;
   glm::mat4 transformation;
   transformation = glm::lookAt(glm::vec3(_camX, _camY, _camZ), glm::vec3(0, 0, 0), glm::vec3(j, 1, 0));
   _shader.setUniform("view", transformation);
}

void		GameEngine::zoomCam()
{
   if (_camY > 1 && _camZ > 1)
   {
      _camY -= 0.5;
      _camZ -= 0.5;
   }
   updateCam();
}

void		GameEngine::deZoomCam()
{
   if (_camY < 25 && _camZ < 25)
   {
      _camY += 0.5;
      _camZ += 0.5;
   }
   updateCam();
}


void GameEngine::cleanObj()
{
  while (!_obj.empty())
    _obj.pop_back();

}

bool GameEngine::update()
{
   int	i = 0;

   if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
   {
     SaveMap Sauv(this->_obj);
     cleanObj();
     _context.stop();
      return false;
   }
   if (_endProgram == true)
      return (false);
   if (_input.getKey(SDLK_m))
      zoomCam();
   if (_input.getKey(SDLK_l))
      deZoomCam();
   while (i < this->_nbia)
      this->_lia[i++]->run();
   if (_input.getKey(SDLK_p))
      rotateCam(0,1);
   if (_input.getKey(SDLK_o))
      rotateCam(0,-1);
   _context.updateClock(_clock);
   _context.updateInputs(_input);
   for (size_t i = 0; i < _obj.size(); ++i)
      _obj[i]->update(_clock, _input);
   return true;
}

void GameEngine::draw()
{
   _shader.bind();
   for (size_t i = 0; i < _obj.size(); ++i)
   {
      if (_obj[i]->getName() == "Player")
      {
      	 _obj[i]->draw(_shader, _clock);
      	 ((Player *)_obj[i])->drawBombe(_shader, _clock);
        if (((Player *)_obj[i])->getDeath() == true)
        {
          Loose(((Player *)_obj[i])->getlvl());
          _endProgram = true;
        }
      }
      if (_obj[i]->getName() != "Player")
	 for (size_t j = 0; j < _obj[i]->_lpos.size(); ++j)
	 {
	    _obj[i]->translate2(_obj[i]->_lpos[j].first, _obj[i]->_lpos[j].second);
	    _obj[i]->draw(_shader, _clock);
	    _obj[i]->translate2(-_obj[i]->_lpos[j].first, -_obj[i]->_lpos[j].second);
	 }
   }
   _context.flush();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

gdl::SdlContext GameEngine::getContext() const
{
  return this->_context;
}

gdl::Clock &GameEngine::getClock()
{
  return this->_clock;
}

gdl::BasicShader& GameEngine::getShader()
{
  return this->_shader;
}

std::vector<AObject*> GameEngine::getObj() const
{
  return (this->_obj);
}

AObject*		GameEngine::getObjByPos(std::pair<int, int> pos) const
{
   for (size_t i = 0; i < _obj.size(); ++i)
   {
      if (_obj[i]->getName() != "sol")
	 for (size_t j = 0; j < _obj[i]->_lpos.size(); ++j)
	 {
	    if (_obj[i]->_lpos[j].first == pos.first && _obj[i]->_lpos[j].second == pos.second)
	       return (_obj[i]);
	 }
   }
   return (NULL);
}

std::pair<int, int>	GameEngine::getPosPlayer(std::pair<int, int> pos)
{
  std::pair<int, int>	tmp;
  std::pair<int, int>	tmp2;
  int			diff;
  int			diff2;
  int			t = 0;
  int			i = 1;


  tmp = this->_obj[8]->getPos();
  diff = abs(tmp.first - pos.first) + abs(tmp.second - pos.second);
  while (i < (this->_nbPlayer + this->_nbia))
    {
      tmp2 = this->_obj[i + 8]->getPos();
      diff2 = abs(tmp2.first - pos.first) + abs(tmp2.second - pos.second);
      if (diff2 != 0 && diff2 < diff)
	t = i;
      i++;
    }
  return this->_obj[t+8]->getPos();
}
