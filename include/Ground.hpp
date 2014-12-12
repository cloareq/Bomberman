#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "AObject.hpp"
#include "GameEngine.hpp"
#include "Texture.hh"
#include "Geometry.hh"

class Ground : public AObject
{
private:
 gdl::Texture _texture;
 gdl::Geometry _geometry;
 float _speed;
public:
   Ground(std::pair<int, int> pos, std::string name, int size);
   virtual ~Ground() {}
   virtual bool initialize();
   virtual void update(gdl::Clock const &clock, gdl::Input &input);
   virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};
