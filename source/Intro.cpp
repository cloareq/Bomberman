//
// Intro.cpp for hello in /home/ledu/projet/cpp_bomberman/source
// 
// Made by ledu
// Login   <ledu@epitech.net>
// 
// Started on  Sat Jun 14 11:34:51 2014 ledu
// Last update Sat Jun 14 15:44:56 2014 ledu
//

#include "Intro.hpp"

Intro::Intro()
{
  this->_movie = new sfe::Movie;
}

Intro::~Intro()
{
  delete this->_movie;
}

void	Intro::openFromFile(std::string str)
{
  _movie->openFromFile(str);
}

void	Intro::Play()
{
  _movie->play();
}

void	Intro::resizeToFrame(int x, int y)
{
  _movie->resizeToFrame(0, 0, x, y);
}

sfe::Movie	*Intro::getMovie()
{
  return (_movie);
}
