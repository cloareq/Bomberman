//
// Score.hpp for Score in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Tue May 13 18:28:13 2014 lebeau_c
// Last update Sat Jun  7 20:13:56 2014 lebeau_c
//

#ifndef SCORE_H
#define SCORE_H

#include "Manager.hpp"
#include "ADisplay.hpp"
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define FILE_SCORE	".score"
#define FILE_SCORE2	".score2"

class Score : public ADisplay
{
public:
   Score(Manager &);
   ~Score();
   void	readScore(Manager &);
   void	writeScore(std::string, int);
   void	deleteFile();
   void	initialize();
   void draw(Manager &);
   void display(Manager &);
   void go_back(Manager &);
  std::vector<std::pair<std::string, int> >	CheckScoreBeforeWrite(std::string, int);
  std::vector<std::pair<std::string, int> >	CheckScoreBeforeWriteSecond(std::string, int, std::vector<std::pair<std::string, int> >);

private:
   sf::Texture	_background;
   sf::Sprite	_backS;
   sf::Font	_font;
   sf::Text	_text;
   std::string	_fileName;
   int		_score;
};

#endif /*SCORE_H*/
