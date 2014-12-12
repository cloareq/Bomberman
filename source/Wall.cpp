//
// Wall.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Tue Jun  3 10:39:50 2014 Antoine BERGHEN
// Last update Wed Jun 11 18:29:06 2014 Kiril
//

#include "GameEngine.hpp"
//#include "Wall.hpp"

Wall::Wall(std::pair<int, int> pos, std::string name, int size):
  AObject(pos, name, size, WALL)
{
  initialize();
}

bool Wall::initialize()
{
  if (_texture.load("./assets/mur.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));

  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));
   _geometry.build();
   return (true);
}

void Wall::update(gdl::Clock const &clock, gdl::Input &input)
 {}

void Wall::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
}
