//
// Intro.hpp for hello in /home/ledu/projet/cpp_bomberman/source
// 
// Made by ledu
// Login   <ledu@epitech.net>
// 
// Started on  Sat Jun 14 11:28:21 2014 ledu
// Last update Sat Jun 14 15:41:42 2014 ledu
//

#ifndef	INTRO_HPP_
#define	INTRO_HPP_

#include <iostream>
#include <string>
#include "Movie.hpp"

class	Intro
{
public :
  Intro();
  ~Intro();
  void	openFromFile(std::string);
  void	Play();
  void  resizeToFrame(int, int);
  sfe::Movie *getMovie();
private :
  sfe::Movie *_movie;

};

#endif
