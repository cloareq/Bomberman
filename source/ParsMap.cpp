//
// ParsMap.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Tue Jun  3 10:34:30 2014 Antoine BERGHEN
//

#include "AObject.hpp"
#include "ParsMap.hpp"
#include "error.hpp"

ParsMap::ParsMap(std::string name, std::vector<AObject *> &obj, GameEngine *ge)
: _ge(ge)
{
   this->_NameMap = name;
   this->OpenMapFile(name, obj);
   obj[0]->setBonus(obj[1], obj[4], obj[5]);
   obj[0]->setBonus(obj[1], obj[5], obj[4]);
}

ParsMap::~ParsMap()
{

}

int	ParsMap::getXMap() const
{
  return (this->_XMap);
}

int	ParsMap::getYMap() const
{
  return (this->_YMap);
}

void ParsMap::OpenMapFile(std::string name, std::vector<AObject *> &obj)
{
  this->_FileMapOpen = new std::ifstream(name.c_str(), std::ios::in);
  if (*this->_FileMapOpen)
    this->ReadFileMap(obj);
  else
    error_end("Error open Map");
}

void	ParsMap::ReadFileMap(std::vector<AObject *> &obj)
{
  std::string line;
  std::string result;

  this->_XMap = 0;
  this->_YMap = 0;
  while (std::getline(*this->_FileMapOpen, line))
    {
      result += line;
      if (this->_YMap == 0)
	this->_XMap = result.size() - 1;
      result += "\n";
      this->_YMap++;
    }
  this->checkMap(result, obj);
}

void	ParsMap::checkMap(std::string result, std::vector<AObject *> &obj)
{
  const char *mapR = result.c_str();
  int	i = 0;
  int	x = 0;
  int	y = 0;
  int	verif = 0;

  AObject *wall = new Wall(std::make_pair(x, y), "SOLID", 1);
  AObject *caisse = new Cube(std::make_pair(x, y), "SOFT", 1);
  AObject *ground = new Ground(std::make_pair(x, y), "sol", 1);
  AObject *fire = new Fire(std::make_pair(x, y), "fire", 1);
  AObject *bombe = new Bomb(std::make_pair(5, 5), "Bomb", 0.0025, 1, 3, clock());
  AObject *blife = new Blife(std::make_pair(x, y), "blife", 0.05);
  AObject *bpowerfull = new Bpowerfull(std::make_pair(x, y), "bpowerfull", 0.2);
  AObject *pp1 = new Pp1(std::make_pair(x, y), "P1", 1.5);
  AObject *pp2 = new Pp2(std::make_pair(x, y), "P2", 1.5);
  obj.push_back(wall);
  obj.push_back(caisse);
  obj.push_back(ground);
  obj.push_back(fire);
  obj.push_back(blife);
  obj.push_back(bpowerfull);
  obj.push_back(pp1);
  pp1->_lpos.push_back(std::make_pair(1,1));
  obj.push_back(pp2);
  pp2->_lpos.push_back(std::make_pair(100,100));
 while (mapR[i])
    {
      switch (mapR[i]) {
      case '\n':
	x = 0;
	y++;
	verif = 1;
	break;
      case SOLID_WALL + 48:
	 wall->_lpos.push_back(std::make_pair(x, y));
	 break;
      case SOFT_WALL + 48:
	 caisse->_lpos.push_back(std::make_pair(x, y));
	 break;
      }
      ground->_lpos.push_back(std::make_pair(x, y));
      if (verif != 1)
	x++;
      else
	verif = 0;
      i++;
    }
  ground->_lpos.pop_back();
  obj.push_back(bombe);
  obj.pop_back();
}

std::ifstream *ParsMap::getFileMapOpen()
{
  return (this->_FileMapOpen);
}
