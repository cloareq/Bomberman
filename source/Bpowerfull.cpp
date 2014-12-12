//
// Bpowerfull.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Sat Jun 14 11:44:30 2014 Antoine BERGHEN
// Last update Sun Jun 15 16:20:36 2014 lebeau_c
//

#include "Bpowerfull.hpp"

Bpowerfull::Bpowerfull(std::pair<int, int> pos, std::string name, float size):
  AObject(pos, name, size)
 {
   initialize();
 }

bool Bpowerfull::initialize()
{
   if (_model.load("./assets/star.FBX") == -1)
   {
      std::cout << "error load" << std::endl;
      return (-1);
   }
   rotate(glm::vec3(0, 0, 1), -90);
   rotate(glm::vec3(0, 1, 0), 90);
   return (0);
}

void Bpowerfull::update(gdl::Clock const &clock, gdl::Input &input)
 {
 }

void Bpowerfull::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
    _model.draw(shader, getTransformation(), clock.getElapsed());
 }
