//
// Fire.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Tue Jun  3 10:37:49 2014 Antoine BERGHEN
// Last update Sat Jun 14 20:35:22 2014 lebeau_c
//

#include "GameEngine.hpp"

Fire::Fire(std::pair<int, int> pos, std::string name, float size) : AObject(pos, name, size)
 {
   initialize();
 }

 bool Fire::initialize()
 {
   if (_model.load("./assets/fire.FBX") == -1)
   {
      std::cout << "error load" << std::endl;
      return (-1);
   }
   return (0);
}

void Fire::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void Fire::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
  _model.draw(shader, getTransformation(), clock.getElapsed());
 }
