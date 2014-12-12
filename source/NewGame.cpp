//
// Score.cpp for score in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 11:47:10 2014 lebeau_c
// Last update Sun Jun 15 19:17:16 2014 lebeau_c
//

#include "dirent.h"
#include "Manager.hpp"
#include "Menu.hpp"
#include "NewGame.hpp"
#include "ParsMapSecond.hpp"

NewGame::NewGame(Manager & manag) : ADisplay()
{
   _status = 0;
   std::cout << "Création du NewGame\n" << std::endl;
   initialize();
   _backS.setTexture(_background);
   this->_fileName = ".NewGame";
   _back = 0;
}

void	NewGame::initialize()
{
   if (!_background.loadFromFile("img/newgame.png"))
      std::cout<<"Erreur durant le chargement d'une texture"<<std::endl;
   fill_vectors();
   initializeIt();
   initializeText();
}

void	NewGame::draw(Manager & manag)
{
   _mouseX = manag.getMouseX();
   _mouseY = manag.getMouseY();
   go_back(manag);
   manag.get_app()->clear();
   manag.get_app()->draw(_backS);
   selectMap(manag);
   selectPlayer(manag);
   selectIA(manag);
   go_launch(manag);
   manag.resetButton();
   drawMap(manag);
   drawPlayer(manag);
   drawIA(manag);
   display(manag);
   go_launch(manag);
}

void	NewGame::initializeText()
{
   _font.loadFromFile("img/badaboom.ttf");
   _text.setFont(_font);
   _text.setStyle(sf::Text::Bold);
   _text.setColor(sf::Color::Red);
   _text.setCharacterSize(30);
}

void	NewGame::drawMap(Manager & manag)
{
  ParsMapSecond cutname(*_it_map);
  std::string shortname = cutname.getShortName();

  _text.setString(shortname);
  _text.setPosition(160, 150);
  manag.get_app()->draw(_text);
}

void	NewGame::drawPlayer(Manager & manag)
{
   _text.setString(*_it_player);
   _text.setPosition(205, 275);
   manag.get_app()->draw(_text);
}

void	NewGame::drawIA(Manager & manag)
{
   _text.setString(*_it_IA);
   _text.setPosition(205, 400);
   manag.get_app()->draw(_text);
}

void	NewGame::initializeIt()
{
   _it_map = _maps.begin();
   _it_player = _players.begin();
   _it_IA = _IA.begin();
}

void	NewGame::selectMap(Manager & manag)
{
  if (_mouseX >= 280 && _mouseX <= 350 && _mouseY >= 150 && _mouseY <= 190)
     if (manag.getButton() == 1)
	if (_it_map + 1 != _maps.end())
	   _it_map++;
     if (_mouseX >= 80 && _mouseX <= 150 && _mouseY >= 150 && _mouseY <= 190)
     {
	if (manag.getButton() == 1)
	   if (_it_map != _maps.begin())
	      _it_map--;
     }
}

void	NewGame::selectPlayer(Manager & manag)
{
   if (_mouseX >= 280 && _mouseX <= 350 && _mouseY >= 270 && _mouseY <= 310)
      if (manag.getButton() == 1)
	 if (_it_player + 1 != _players.end())
	    _it_player++;
   if (_mouseX >= 80 && _mouseX <= 150 && _mouseY >= 270 && _mouseY <= 310)
      if (manag.getButton() == 1)
	 if (_it_player != _players.begin())
	    _it_player--;
}

void	NewGame::selectIA(Manager & manag)
{
   if (_mouseX >= 280 && _mouseX <= 350 && _mouseY >= 390 && _mouseY <= 430)
      if (manag.getButton() == 1)
	 if (_it_IA + 1 != _IA.end())
	    _it_IA++;
   if (_mouseX >= 80 && _mouseX <= 150 && _mouseY >= 390 && _mouseY <= 430)
      if (manag.getButton() == 1)
	 if (_it_IA != _IA.begin())
	    _it_IA--;
}

void	my_itoa(int value, std::string& buf, int base)
{
  int i = 30;

  buf = "";
  for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;

}

void	NewGame::fill_vectors()
{
   DIR	*rep = opendir("./maps");
   int	nb = 1;
   std::string str;

   if (rep != NULL)
   {
      struct dirent * ent;
      while ((ent = readdir(rep)) != NULL)
	 if (ent->d_name[0] != '.')
	      _maps.push_back(ent->d_name);
      closedir(rep);
   }
  _players.push_back("1");
  _players.push_back("2");
  _IA.push_back("0");
  while (nb <= NB_IA)
    {
      my_itoa(nb, str, 10);
      _IA.push_back(str);
      nb++;
    }
}

void	NewGame::go_back(Manager & manag)
{
   if (_mouseX >= 60 && _mouseX <= 130 && _mouseY >= 494 && _mouseY <= 524)
   {
      if (manag.getButton() == 1)
      {
	 setStatut(0);
	 _back = 1;
	 manag.resetButton();
      }
   }
}

void	NewGame::go_launch(Manager & manag)
{
   if (_mouseX >= 460 && _mouseX <= 780 && _mouseY >= 480 && _mouseY <= 524)
      if (manag.getButton() == 1)
      {
	 manag.add_option_game(*_it_map, *_it_player, *_it_IA);
	 lunch(manag);
	 manag.resetButton();
	 manag.setAlreadyLaunch(1);
      }
}

void	NewGame::display(Manager & manag)
{
   manag.get_app()->display();
}

NewGame::~NewGame(){
}
