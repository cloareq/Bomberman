//
// Manager.hpp for Manager in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 21:10:42 2014 lebeau_c
// Last update Sun Jun 15 12:18:08 2014 lebeau_c
//

#ifndef MANAGER_H
#define MANAGER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Thread.hpp"

#define WD_X 800
#define WD_Y 586

class Manager
{
public:
   sf::RenderWindow		*get_app() const;
   int				getStatut() const;
   void				setStatut(int);
   void				setMouse(int, int);
   int				getMouseX() const;
   int				getMouseY() const;
   int				getButton() const;
   void				setButton(sf::Mouse::Button);
   void				setThread(Thread *);
   void				resetButton();
   void				setAlreadyLaunch(int);
   static Manager *		getInstance();
   void				add_option_game(std::string, std::string, std::string);
   std::string			getMap() const;
   int				getNBPlayer() const;
   int getNBIA() const;

public:
  Manager();
  ~Manager();

private:
   sf::RenderWindow			*_app;
   int					_statut;
   int					_mouseX;
   int					_mouseY;
   int					_left;
   int					_alreadyLaunch;
   std::string				_Nmap;
   int					_player;
   int					_IA;
   Thread				*t1;
   static Manager			*_singleton;
   static int				_s;

};

#endif /*MANAGER_H*/
