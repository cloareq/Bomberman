#include "GameEngine.hpp"

Pp1::Pp1(std::pair<int, int> pos, std::string name, float size) : AObject(pos, name, size)
 {
    initialize();
    _position.y = 2;
 }

 bool Pp1::initialize()
 {
   if (_model.load("./assets/1.fbx") == -1)
   {
      std::cout << "error load" << std::endl;
      return (-1);
   }
   rotate(glm::vec3(1, 0, 0), 90);
   return (0);
}

void Pp1::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void Pp1::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
  _model.draw(shader, getTransformation(), clock.getElapsed());
 }
