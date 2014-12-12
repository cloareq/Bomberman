//
// Blife.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Fri Jun 13 16:53:55 2014 Antoine BERGHEN
// Last update Sun Jun 15 20:15:40 2014 lebeau_c
//

#ifndef BLIFE_H
#define BLIFE_H

#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "AObject.hpp"
#include "GameEngine.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Blife: public AObject
{
private:
 gdl::Texture	_texture;
 gdl::Geometry	_geometry;
 gdl::Model	_model;

public:
   Blife(std::pair<int, int> pos, std::string name, float size);
   virtual ~Blife() {}
   virtual bool initialize();
   virtual void update(gdl::Clock const &clock, gdl::Input &input);
   virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /*BLIFE_H*/
