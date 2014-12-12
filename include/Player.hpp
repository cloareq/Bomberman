//
// Player.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Fri May  9 11:12:52 2014 Antoine BERGHEN
// Last update Sun Jun 15 18:59:55 2014 Kiril
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdlib>

#include <list>
#include <vector>
#include <ctime>

#include "AObject.hpp"
#include "Inventory.h"
#include "Model.hh"
#include "Texture.hh"
#include "GameEngine.hpp"
#include "Bomb.hpp"

#define VIT 4

class Player : public AObject
{
private:
  int				_score;
  float				_speed;
  size_t			_Life;
  int				_Lvl;
  int				_right;
  int				_down;
  int				_left;
  int				_up;
  int				_nbBombes;
  int				_VRight;
  int				_VUp;
  int				_fx;
  int				_fy;
  bool				_death;
  bool				_power;
  gdl::Texture			_texture;
  gdl::Model			_model;
  std::vector<Bonus>		_InventoryPlayer;
  GameEngine			*_ge;
  std::vector<AObject *>	_bombes;
  clock_t			_t;
  Pp1				*_pp1;
  Pp2				*_pp2;

public:
   Player(std::pair<int, int> pos, std::string name, float size, int lvl, GameEngine *ge);
  ~Player();
  void			PutBombe();
  bool			CheckColision(float, float);
  bool			CheckColisionLeft(float, float);
  void			PickUpBonus(int);
  void			ChangeSpeed(int);
  int			GetScore() const;
  void			SetScore(int);
  std::vector<Bonus>	GetInventoryPlayer() const;
  void			SetInventoryPlayer(std::vector<Bonus>);
  size_t		getLife() const;
  void			SetLife(size_t);
  int			GetLvl() const;
  void			drawPlayer(gdl::AShader &, gdl::Clock const &);
  void			drawIA();
  void			draw(gdl::AShader &shader, gdl::Clock const &clock);
  void			erase_caisse(int x, int y, GameEngine *_ge);
  bool			burn_wall(int x, int y, GameEngine *_ge);
  GameEngine *		getManager() const;
  void			update(gdl::Clock const &clock, gdl::Input &input);
  void			update_p1(gdl::Clock const &clock, gdl::Input &input);
  void			update_p2(gdl::Clock const &clock, gdl::Input &input);
  void			up(gdl::Clock const &clock);
  void			down(gdl::Clock const &clock);
  void			right(gdl::Clock const &clock);
  void			left(gdl::Clock const &clock);
  void			setPositions();
  bool			init();
  bool			checkBonus(AObject *);
  void			print_position();
  void			drawFire(int x, int y, clock_t clock);
  void			drawBombe(gdl::AShader &shader, gdl::Clock const &Clock);
  void			erase_fire(int x, int y);
  void			check_fire();
  void			Died(int x, int y);
  bool			getDeath() const;
  int getlvl() const;
};

#endif
