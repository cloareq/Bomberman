//
// Bpowerfull.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Sat Jun 14 11:45:16 2014 Antoine BERGHEN
// Last update Sun Jun 15 20:15:32 2014 lebeau_c
//

#ifndef BPOWERFULL_H
#define BPOWERFULL_H

#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "AObject.hpp"
#include "GameEngine.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Bpowerfull: public AObject
{
private:
 gdl::Texture	_texture;
 gdl::Geometry	_geometry;
 gdl::Model	_model;

public:
   Bpowerfull(std::pair<int, int> pos, std::string name, float size);
   virtual ~Bpowerfull() {}
   virtual bool initialize();
   virtual void update(gdl::Clock const &clock, gdl::Input &input);
   virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /*BPOWERFULL_H*/
