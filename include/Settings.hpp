//
// Settings.hpp for hello in /home/ledu/projet/cpp_bomberman/Menu/src
//
// Made by ledu
// Login   <ledu@epitech.net>
//
// Started on  Thu May 22 10:55:09 2014 ledu
// Last update Thu May 22 12:02:02 2014 lebeau_c
//

#ifndef SETTINGS_HH_
#define SETTINGS_HH_

#include "Manager.hpp"
#include "ADisplay.hpp"

class Settings : public ADisplay
{
public:
   Settings(Manager &);
   ~Settings();
   void loadFile();
   void getSettings();
   void addSettings();
   void	deleteFile();
   void	createFile();
   void	initialize();
   void draw(Manager &);
   void display(Manager &);
   void go_back(Manager &);


private:
   sf::Texture	_background;
   sf::Sprite	_backS;
   std::string	_fileName;
};

#endif /*SETTINGS_HH_*/
