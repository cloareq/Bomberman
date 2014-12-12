//
// Blife.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Fri Jun 13 16:55:19 2014 Antoine BERGHEN
// Last update Sun Jun 15 17:51:05 2014 lebeau_c
//

#include "Blife.hpp"

Blife::Blife(std::pair<int, int> pos, std::string name, float size):
  AObject(pos, name, size)
 {
   initialize();
 }

bool Blife::initialize()
{
   if (_model.load("./assets/newcoeur.fbx") == -1)
   {
      std::cout << "error load" << std::endl;
      return (-1);
   }
   rotate(glm::vec3(0, 0, 1), -90);
   rotate(glm::vec3(0, 1, 0), 90);
   return (0);
}

void Blife::update(gdl::Clock const &clock, gdl::Input &input)
 {
 }

void Blife::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
    _model.draw(shader, getTransformation(), clock.getElapsed());
 }
