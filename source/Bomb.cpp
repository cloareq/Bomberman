//
// Bomb.cpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Mon May 12 10:52:07 2014 Antoine BERGHEN
// Last update Thu Jun 12 17:45:55 2014 Kiril
//

#include "Bomb.hpp"

Bomb::Bomb(std::pair<int, int> pos, std::string name, float size, size_t range, size_t timer, clock_t t) : AObject(pos, name, size, BOMB)
 {
   this->_Range = range;
   this->_Timer = timer;
   _t = t;
   _destruction = false;
   initialize();
 }

bool Bomb::initialize()
 {
  if (_model.load("./assets/bomb.fbx") == -1)
  {
    std::cout << "error load" << std::endl;
    return (-1);
  }
  return (0);
}

void Bomb::update(gdl::Clock const &clock, gdl::Input &input)
 {
 }

void Bomb::draw(gdl::AShader &shader, gdl::Clock const &Clock)
 {
  _destruction = false;
  if ((((float)clock() - (float)_t)/CLOCKS_PER_SEC) > _Timer)
    _destruction = true;
  _model.draw(shader, getTransformation(), Clock.getElapsed());
 }

void	Bomb::Explose()
{

}

size_t	Bomb::GetTimer() const
{
  return (this->_Timer);
}

size_t	Bomb::GetRange() const
{
  return (this->_Range);
}

void	Bomb::SetTimer(size_t timer)
{
  this->_Timer = timer;
}

void	Bomb::SetRange(size_t range)
{
  this->_Range = range;
}

bool Bomb::getDestruction() const
{
  return _destruction;
}

void Bomb::setDestruction(bool val)
{
  _destruction = val;
}
