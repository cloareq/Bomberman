#include "GameEngine.hpp"

Pp2::Pp2(std::pair<int, int> pos, std::string name, float size) : AObject(pos, name, size)
 {
   initialize();
   _position.y = 2;
 }

 bool Pp2::initialize()
 {
   if (_model.load("./assets/2.fbx") == -1)
   {
      std::cout << "error load" << std::endl;
      return (-1);
   }
   rotate(glm::vec3(1, 0, 0), 90);
   return (0);
}

void	 Pp2::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void	Pp2::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
	_model.draw(shader, getTransformation(), clock.getElapsed());
 }
