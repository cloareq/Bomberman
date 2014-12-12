//
// main.cpp for  in /home/kiril/cpp_bomberman/source
// 
// Made by Kiril
// Login   <kiril@epitech.net>
// 
// Started on  Sat Jun 14 22:46:17 2014 Kiril
// Last update Sun Jun 15 01:00:40 2014 hardel_c
//

#include <unistd.h>
#include <SFML/Audio.hpp>
#include <ctime>
#include "Menu.hpp"
#include "Manager.hpp"
#include "Score.hpp"
#include "LoadGame.hpp"
#include "NewGame.hpp"
#include "Settings.hpp"
#include "Music.hpp"
#include "Movie.hpp"

int main()
{
   Manager	manag;
   Menu		menu(manag);

   srand(time(NULL));
   menu.video("intro.ogv", manag);
   menu.init_musique();
   menu.setStatut(1);
   menu.gereEvent(manag);
}
