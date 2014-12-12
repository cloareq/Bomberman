//
// ParsMap.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Tue Jun  3 10:34:41 2014 Antoine BERGHEN
// Last update Sat Jun 14 11:46:16 2014 Antoine BERGHEN
//

#ifndef PARSMAP_HPP
#define PARSMAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AObject.hpp"
#include "Map.h"
#include "Wall.hpp"
#include "Player.hpp"
#include "Blife.hpp"
#include "Bpowerfull.hpp"
#include "GameEngine.hpp"
#include <utility>

class ParsMap
{
public:
  ParsMap(std::string, std::vector<AObject *>&, GameEngine *ge);
  ~ParsMap();
  void	PutDataInVector(int, int, int, std::vector<AObject *>&);
  void	OpenMapFile(std::string, std::vector<AObject *>&);
  void	checkMap(std::string, std::vector<AObject *>&);
  std::ifstream *getFileMapOpen();
  void	ReadFileMap(std::vector<AObject *>&);
  int	getXMap() const;
  int	getYMap() const;

private:
  std::ifstream *_FileMapOpen;
  std::string	_NameMap;
  int		_XMap;
  int		_YMap;
  GameEngine *_ge;
};
#endif
