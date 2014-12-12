//
// Score.cpp for score in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 11:47:10 2014 lebeau_c
// Last update Thu Jun 12 16:26:52 2014 ledu
//

#include "Menu.hpp"
#include "Settings.hpp"

Settings::Settings(Manager & manag) : ADisplay()
{
   _status = 0;
   std::cout << "Création du Settings\n" << std::endl;
   initialize();
   _backS.setTexture(_background);
   this->_fileName = ".Settings";
   _back = 0;
}

void	Settings::draw(Manager & manag)
{
   go_back(manag);
   manag.get_app()->clear();
   manag.get_app()->draw(_backS);
   display(manag);
}

void	Settings::initialize()
{
   if (!_background.loadFromFile("img/Settings.png"))
      std::cout<<"Erreur durant le chargement d'une texture"<<std::endl;
}

void	Settings::go_back(Manager & manag)
{
   _mouseX = manag.getMouseX();
   _mouseY = manag.getMouseY();
   if (_mouseX >= 680 && _mouseX <= 758 && _mouseY >= 532 && _mouseY <= 567)
     {
       if (manag.getButton() == 1)
	 {
	   setStatut(0);
	   _back = 1;
	   manag.resetButton();
	 }
     }
   else
     manag.resetButton();
}

void	Settings::display(Manager & manag)
{
   manag.get_app()->display();
}

void	Settings::loadFile()
{
}

void	Settings::getSettings()
{
}

void	Settings::createFile()
{
}

void	Settings::deleteFile()
{
}

void	Settings::addSettings()
{
}

Settings::~Settings()
{
}
