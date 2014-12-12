#ifndef PP1_H
#define PP1_H
#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Texture.hh"
#include "Model.hh"
#include "Geometry.hh"

class Pp1 : public AObject
{
private:
 gdl::Texture	_texture;
 gdl::Geometry	_geometry;
 gdl::Model	_model;
 float		_speed;
public:
   Pp1(std::pair<int, int>, std::string name, float size);
   ~Pp1() {}
   bool initialize();
   void update(gdl::Clock const &clock, gdl::Input &input);
   void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /*PP1_H*/
