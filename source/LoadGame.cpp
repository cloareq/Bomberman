//
// Score.cpp for score in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 11:47:10 2014 lebeau_c
// Last update Sun Jun 15 21:00:47 2014 ledu
//

#include "Manager.hpp"
#include "Menu.hpp"
#include "LoadGame.hpp"

LoadGame::LoadGame(Manager & manag) : ADisplay()
{
   _status = 0;
   std::cout << "Création du LoadGame\n" << std::endl;
   initialize();
   _backS.setTexture(_background);
   this->_fileName = ".LoadGame";
   _back = 0;
}

void	LoadGame::draw(Manager & manag)
{
  _mouseX = manag.getMouseX();
  _mouseY = manag.getMouseY();
  go_back(manag);
  manag.get_app()->clear();
  manag.get_app()->draw(_backS);
  launchGame(manag);
  manag.resetButton();
  display(manag);
}

void	LoadGame::initialize()
{
   if (!_background.loadFromFile("img/LoadGame.png"))
      std::cout<<"Erreur durant le chargement d'une texture"<<std::endl;
}

void	LoadGame::go_back(Manager & manag)
{
  if (_mouseX >= 660 && _mouseX <= 750 && _mouseY >= 494 && _mouseY <= 550)
    {
      if (manag.getButton() == 1)
	{
	  setStatut(0);
	  _back = 1;
	  manag.resetButton();
	}
    }
}

void	LoadGame::launchGame(Manager & manag)
{
  if (_mouseX >= 150 && _mouseX <= 640 && _mouseY >= 360 && _mouseY <= 420)
    {
      if (manag.getButton() == 1)
	{
	  std::cout << "Can't load the last game" << std::endl;
	  manag.resetButton();
	}
    }
}

void	LoadGame::display(Manager & manag)
{
   manag.get_app()->display();
}

void	LoadGame::loadFile()
{
}

void	LoadGame::getLoadGame()
{

}

void	LoadGame::createFile()
{

}

void	LoadGame::deleteFile()
{

}

void	LoadGame::addLoadGame()
{

}

LoadGame::~LoadGame()
{

}
