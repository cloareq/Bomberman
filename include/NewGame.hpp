//
// NewGame.hpp for hello in /home/ledu/projet/cpp_bomberman/Menu/src
//
// Made by ledu
// Login   <ledu@epitech.net>
//
// Started on  Thu May 22 10:56:51 2014 ledu
// Last update Sun Jun 15 19:17:37 2014 lebeau_c
//

#ifndef NEWGAME_HH_
#define NEWGAME_HH_

#include <sstream>
#include "Manager.hpp"
#include "ADisplay.hpp"

#define NB_IA 3

class NewGame : public ADisplay
{
public:
   NewGame(Manager &);
   ~NewGame();
   void initialize();
   void	initializeIt();
   void initializeText();
   void draw(Manager &);
   void display(Manager &);
   void go_back(Manager &);
   void go_launch(Manager &);
   void	fill_vectors();
   void selectMap(Manager &);
   void selectPlayer(Manager &);
   void selectIA(Manager &);
   void	drawMap(Manager &);
   void	drawPlayer(Manager &);
   void	drawIA(Manager &);

private:
   sf::Texture	_background;
   sf::Sprite	_backS;
   std::string			_fileName;
   std::vector<std::string> _maps;
   std::vector<std::string> _players;
   std::vector<std::string> _IA;
   std::vector<std::string>::iterator _it_map;
   std::vector<std::string>::iterator _it_player;
   std::vector<std::string>::iterator _it_IA;
};

int lunch(Manager &);

#endif /*SCORE_H*/
