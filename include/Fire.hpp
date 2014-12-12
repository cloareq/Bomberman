#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Texture.hh"
#include "Model.hh"
#include "Geometry.hh"

class Fire : public AObject
{
private:
 gdl::Texture _texture;
 gdl::Geometry _geometry;
 gdl::Model _model;
 float _speed;

public:
   Fire(std::pair<int, int>, std::string name, float size);
   ~Fire() {}
   bool initialize();
   void update(gdl::Clock const &clock, gdl::Input &input);
   void draw(gdl::AShader &shader, gdl::Clock const &clock);
};
