//
// LoadGame.hpp for hello in /home/ledu/projet/cpp_bomberman/Menu/src
//
// Made by ledu
// Login   <ledu@epitech.net>
//
// Started on  Thu May 22 10:57:56 2014 ledu
// Last update Sun Jun 15 15:54:33 2014 ledu
//

#ifndef LOADGAME_HH_
#define LOADGAME_HH_

#include "Manager.hpp"
#include "ADisplay.hpp"

class LoadGame : public ADisplay
{
public:
   LoadGame(Manager &);
   ~LoadGame();
   void loadFile();
   void getLoadGame();
   void addLoadGame();
   void	deleteFile();
   void	createFile();
   void	initialize();
   void draw(Manager &);
   void display(Manager &);
   void go_back(Manager &);
  void	launchGame(Manager &);

private:
   sf::Texture	_background;
   sf::Sprite	_backS;
   std::string	_fileName;
};

#endif /*LOADGAME_H*/
