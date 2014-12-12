//
// Manager.cpp for Manager in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 21:07:33 2014 lebeau_c
// Last update Sun Jun 15 17:57:42 2014 lebeau_c
//

#include <string>
#include <sstream>
#include "Manager.hpp"

Manager		* Manager::_singleton = NULL;

Manager::Manager()
{
   // if (std::getenv("PATH") == NULL)
   //    exit(-1);
   this->_statut = 0;
   std::cout << "Creation Manager" << std::endl;
   this->_app = new sf::RenderWindow(sf::VideoMode(WD_X,WD_Y), "Bomberman" );
   this->_alreadyLaunch = 0;
}

sf::RenderWindow   *Manager::get_app() const
{
   return (_app);
}

Manager		* Manager::getInstance()
{
   if (!_singleton)
      _singleton = new Manager;
   return (_singleton);
}

void	Manager::setMouse(int x, int y)
{
   if (x > 0 && y > 2)
   {
      _mouseX = x;
      _mouseY = y;
   }
}

void	Manager::setButton(sf::Mouse::Button button)
{
   if (button == sf::Mouse::Left && _alreadyLaunch == 0)
      _left = 1;
}

void	Manager::setAlreadyLaunch(int i)
{
   _alreadyLaunch = i;
}

void	Manager::resetButton()
{
   _left = 0;
}

int	Manager::getButton() const
{
   return (_left);
}

int	Manager::getMouseX() const
{
   return (_mouseX);
}

int	Manager::getMouseY() const
{
   return (_mouseY);
}

int	Manager::getStatut() const
{
   return (_statut);
}

void	Manager::setStatut(int st)
{
   _statut = st;
}

void	Manager::setThread(Thread *t)
{
   t1 = t;
}

void	Manager::add_option_game(std::string map,std::string pl,std::string IA)
{
   std::istringstream player(pl);

   _Nmap = map;
   player >> _player;
   std::istringstream AI(IA);
   AI >> _IA;
}

int Manager::getNBPlayer() const
{
   return _player;
}

int Manager::getNBIA() const
{
   return _IA;
}

std::string	Manager::getMap() const
{
   return (_Nmap);
}

Manager::~Manager()
{

}
