//
// Music.cpp for hello in /home/ledu/projet/cpp_bomberman/Menu
//
// Made by ledu
// Login   <ledu@epitech.net>
//
// Started on  Fri May 30 15:32:49 2014 ledu
// Last update Sun Jun  8 18:17:24 2014 lebeau_c
//

#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include "Music.hpp"

Musique::Musique()
{
  this->_mus = new sf::Music;
}

Musique::~Musique()
{
  delete this->_mus;
}

void	Musique::openFromFile(std::string str)
{
  _mus->openFromFile(str);
}

void	Musique::Play()
{
  _mus->play();
}

void	Musique::SetVolume(double vol)
{
   _mus->setVolume(vol);
}

void	Musique::Pause()
{
  _mus->pause();
}
