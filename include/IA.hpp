#ifndef IA_HH_
#define IA_HH_

#pragma once
#include <iostream>
#include "Player.hpp"
//class Player;

class ia
{
private:
  Player *			_player;
  std::pair<int, int>		_target;
  bool				_istarget;
public:
  ia(Player *);
  ~ia();
  bool			isOnTarget();
  e_object		getObj(e_direction);
  bool			check(e_object);
  void			run();
  void			move();
};

#endif
