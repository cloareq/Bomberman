//
// Menu.cpp for Menu in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 21:15:52 2014 lebeau_c
// Last update Sun Jun 15 20:19:20 2014 ledu
//

#include "Setting.hpp"
#include "Score.hpp"
#include "Menu.hpp"
#include "Manager.hpp"

Menu::Menu(Manager & manag) : ADisplay()
{
   _status = 0;
   initialize();
   _backS.setTexture(_background);
   _score = 0;
   _settings = 0;
   _loadgame = 0;
   _newgame  = 0;
   this->_music = new Musique;
   this->_music2 = new Musique;
   this->_movie =  new Intro;
}

void	Menu::video(std::string str, Manager &manag) 
{
  sf::Event	event;
  int          o = 0;
  
  _movie->openFromFile(str);
  _movie->resizeToFrame(800, 586);
  _movie->Play();
  while (manag.get_app()->isOpen())
    {
      while (manag.get_app()->waitEvent(event))
	{
	  if (event.type == sf::Event::KeyPressed)
	    {
	      if (event.type == sf::Event::Closed
		  || event.key.code == sf::Keyboard::Escape)
		o = 1000;
	      if (event.key.code == sf::Keyboard::Space)
		o = 1000;
	    }
	  if (o >= 1000)
	    break;
	  manag.get_app()->clear();
	  manag.get_app()->draw(*(_movie->getMovie()));
	  manag.get_app()->display();
	  o++;
	}
      break;
    }
  delete _movie;
}

void	Menu::init_musique()
{
  this->_music->openFromFile("audio/theme.wav");
  this->_music2->openFromFile("audio/Click.wav");
  this->_music->SetVolume(3);
  this->_music->Play();
}

void	Menu::checkKeys(sf::Event event)
{
  int mus = 0;
  
  if (event.type == sf::Event::KeyPressed)
    {
      if (event.type == sf::Event::Closed
	  || event.key.code == sf::Keyboard::Escape)
	{
	  delete this->_music;
	  delete this->_music2;
	  exit(1);
	}
      if (event.key.code == sf::Keyboard::O)
	{
	  if (mus == 0)
	    {
	      mus = 1;
	      this->_music->Pause();
	    }
	  else
	    {
	      mus = 0;
	      this->_music->Play();
	    }
	}
      if (event.key.code == sf::Keyboard::P)
	delete this->_movie;
    }
}

void	Menu::musiqueClic(sf::Event event, Manager &manag)
{
  if(event.type == sf::Event::MouseButtonPressed)
    {
      this->_music2->Play();
      manag.setButton(event.mouseButton.button);
      event.type = sf::Event::MouseButtonReleased;
    }
}

void	Menu::checkNews()
{
  if (this->getNewGame() != NULL && this->getNewGame()->getBack() == 1)
    {
      this->setStatut(1);
      this->getNewGame()->setBack(0);
      this->getNewGame()->setStatut(0);
    }
}

void	Menu::checkLoad()
{
  if (this->getLoadGame() != NULL && this->getLoadGame()->getBack() == 1)
    {
      this->setStatut(1);
      this->getLoadGame()->setBack(0);
      this->getLoadGame()->setStatut(0);
    }
}

void	Menu::checkScore()
{
  if (this->getScore() != NULL && this->getScore()->getBack() == 1)
    {
      this->setStatut(1);
      this->getScore()->setBack(0);
      this->getScore()->setStatut(0);
    }
}

void	Menu::checkSettings()
{
  if (this->getSettings() != NULL && this->getSettings()->getBack() == 1)
    {
      this->setStatut(1);
      this->getSettings()->setBack(0);
      this->getSettings()->setStatut(0);
    }
}

void	Menu::checkDrawStatus(Manager &manag)
{
  if (this->getStatut() == 1)
    this->draw(manag);
}

void	Menu::checkDrawNew(Manager &manag)
{
  if (this->getNewGame() != NULL && this->getNewGame()->getStatut() == 1)
    this->getNewGame()->draw(manag);
}

void	Menu::checkDrawLoad(Manager &manag)
{
  if (this->getLoadGame() != NULL && this->getLoadGame()->getStatut() == 1)
    this->getLoadGame()->draw(manag);
}

void	Menu::checkDrawScore(Manager &manag)
{
  if (this->getScore() != NULL && this->getScore()->getStatut() == 1)
    this->getScore()->draw(manag);
}

void	Menu::checkDrawSettings(Manager &manag)
{
  if (this->getSettings() != NULL && this->getSettings()->getStatut() == 1)
    this->getSettings()->draw(manag);
}

void	Menu::gereEvent(Manager &manag)
{
  while (manag.get_app()->isOpen())
    {
      sf::Event        event;

      while(manag.get_app()->waitEvent(event)){
	manag.setMouse(event.mouseMove.x, event.mouseMove.y);
	checkKeys(event);
	musiqueClic(event, manag);
	switch (1)
	  {
	  case 1:
	    checkNews();
	  case 2:
	    checkLoad();
	  case 3:
	    checkScore();
	  case 4:
	    checkSettings();
	  case 5:
	    checkDrawStatus(manag);
	  case 6:
	    checkDrawNew(manag);
	  case 7:
	    checkDrawLoad(manag);
	  case 8:
	    checkDrawScore(manag);
	  case 9:
	    checkDrawSettings(manag);
	  }
      }
    }
}

void	Menu::draw(Manager & manag)
{
   switch (1)
     {
     case 1:
       select_new_game(manag);
     case 2:
       select_load_game(manag);
     case 3:
       select_settings(manag);
     case 4:
       select_scores(manag);
     case 5:
	select_exit(manag);
     case 6:
       manag.resetButton();
     }
   manag.get_app()->clear();
   manag.get_app()->draw(_backS);
   display(manag);
}

void	Menu::select_new_game(Manager & manag)
{
   _mouseX = manag.getMouseX();
   _mouseY = manag.getMouseY();
   if (_mouseX >= 590 && _mouseX <= 720 && _mouseY >= 161 && _mouseY <= 190)
     {
	 if (manag.getButton() == 1)
	 {
	    if (_newgame == NULL)
	    {
	       _newgame = new NewGame(manag);
	       setNewGame(_newgame);
	    }
	    getNewGame()->setStatut(1);
	    setStatut(0);
	 }
     }
}

void	Menu::select_load_game(Manager & manag)
{
  _mouseX = manag.getMouseX();
  _mouseY = manag.getMouseY();
  if (_mouseX >= 590 && _mouseX <= 735 && _mouseY >= 226 && _mouseY <= 255)
    {
      if (manag.getButton() == 1)
	{
	  if (_loadgame == NULL)
	    {
	      _loadgame = new LoadGame(manag);
	      setLoadGame(_loadgame);
	    }
	  getLoadGame()->setStatut(1);
	  setStatut(0);
	}
    }
}

void	Menu::select_settings(Manager & manag)
{
  _mouseX = manag.getMouseX();
  _mouseY = manag.getMouseY();
  if (_mouseX >= 590 && _mouseX <= 715 && _mouseY >= 302 && _mouseY <= 330)
    {
      if (manag.getButton() == 1)
	{
	  if (_settings == NULL)
	    {
	      _settings = new Settings(manag);
	      setSettings(_settings);
	    }
	  getSettings()->setStatut(1);
	  setStatut(0);
	}
    }
}

void	Menu::select_scores(Manager & manag)
{
  _mouseX = manag.getMouseX();
  _mouseY = manag.getMouseY();
  if (_mouseX >= 590 && _mouseX <= 700 && _mouseY >= 366 && _mouseY <= 395)
    {
      if (manag.getButton() == 1)
	{
	  if (_score == NULL)
	    {
	      _score = new Score(manag);
	      setScore(_score);
	    }
	  getScore()->setStatut(1);
	  setStatut(0);
	}
    }
}

void	Menu::select_exit(Manager & manag)
{
  _mouseX = manag.getMouseX();
  _mouseY = manag.getMouseY();
  if (_mouseX >= 590 && _mouseX <= 650 && _mouseY >= 430 && _mouseY <= 453)
    {
      if (manag.getButton() == 1)
	 {
	   delete this->_music;
	   delete this->_music2;
	   exit(0);
	 }
    }
}

Score	 * Menu::getScore() const
{
   return (_score);
}

void	 Menu::setScore(Score * score)
{
   _score = score;
}

Settings	 * Menu::getSettings() const
{
   return (_settings);
}

void	 Menu::setSettings(Settings * settings)
{
   _settings = settings;
}

LoadGame	 * Menu::getLoadGame() const
{
   return (_loadgame);
}

void	 Menu::setLoadGame(LoadGame * loadgame)
{
   _loadgame = loadgame;
}

NewGame	 * Menu::getNewGame() const
{
   return (_newgame);
}

void	 Menu::setNewGame(NewGame * newgame)
{
   _newgame = newgame;
}

void	Menu::display(Manager & manag)
{
   manag.get_app()->display();
}

void	Menu::initialize()
{
  if (!_background.loadFromFile("img/menu.png"))
    std::cout<<"Erreur durant le chargement d'une texture"<<std::endl;
}

void	ADisplay::refresh_mouse(sf::Event event)
{
   _mouseX = event.mouseMove.x;
   _mouseY = event.mouseMove.y;
}

Menu::~Menu()
{
}
