//
// Cube.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Fri Jun 13 15:31:18 2014 Antoine BERGHEN
// Last update Sun Jun 15 20:15:25 2014 lebeau_c
//

#ifndef CUBE_H
#define CUBE_H

#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "AObject.hpp"
#include "GameEngine.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Cube: public AObject
{
private:
 gdl::Texture	_texture;
 gdl::Geometry	_geometry;
 float		_speed;
  int		_bonus;

public:
   Cube(std::pair<int, int> pos, std::string name, int size);
   virtual ~Cube() {}
   virtual bool initialize();
   virtual void update(gdl::Clock const &clock, gdl::Input &input);
   virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /*CUBE_H*/
