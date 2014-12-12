//
// Bomb.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Mon May 12 10:48:36 2014 Antoine BERGHEN
// Last update Sun Jun 15 20:16:32 2014 lebeau_c
//

#ifndef BOMB_HPP
#define BOMB_HPP

#pragma once

#include <cstdlib>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ctime>
#include "Model.hh"
#include "Texture.hh"
#include "Geometry.hh"
#include "AObject.hpp"


class Bomb : public AObject
{
private:
 gdl::Texture _texture;
 gdl::Geometry _geometry;
 gdl::Model _model;
 float _speed;
  size_t	_Range;
  size_t	_Timer;
  clock_t _t;
  bool _destruction;

public:
  Bomb(std::pair<int, int> pos, std::string name, float size, size_t, size_t, clock_t);
  virtual ~Bomb() {}
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  void		Explose();
  size_t	GetTimer() const;
  void		SetTimer(size_t);
  size_t	GetRange() const;
  void		SetRange(size_t);
  bool getDestruction() const;
  void setDestruction(bool);
};

#endif
