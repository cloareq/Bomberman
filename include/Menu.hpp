//
// Menu.hpp for Menu.hpp in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Tue May 13 11:00:56 2014 lebeau_c
// Last update Sat Jun 14 18:06:17 2014 ledu
//

#ifndef MENU_H
#define MENU_H

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Manager.hpp"
#include "LoadGame.hpp"
#include "NewGame.hpp"
#include "Score.hpp"
#include "Settings.hpp"
#include "Music.hpp"
#include "ADisplay.hpp"
#include "Intro.hpp"

class Menu : public ADisplay
{
public:
   Menu(Manager &);
  ~Menu();
  void init();
  void draw(Manager &);
  void display(Manager &);
  void	gereEvent(Manager &);
  void	select_bombe(Manager&);
  void	select_new_game(Manager&);
  void	select_load_game(Manager&);
  void	select_settings(Manager&);
  void	select_scores(Manager&);
  void	select_back(Manager&);
  void	select_exit(Manager&);
  void	init_musique();
  void	musiqueClic(sf::Event, Manager&);
  void	checkKeys(sf::Event);
  void	checkNews();
  void	checkLoad();
  void	checkSettings();
  void	checkScore();
  void	checkDrawStatus(Manager&);
  void	checkDrawNew(Manager&);
  void	checkDrawLoad(Manager&);
  void	checkDrawScore(Manager&);
  void	checkDrawSettings(Manager&);
  Score	* getScore() const;
  void		setScore(Score *);
  Settings	* getSettings() const;
  void		setSettings(Settings *);
  LoadGame	* getLoadGame() const;
  void		setLoadGame(LoadGame *);
  NewGame	* getNewGame() const;
  void		setNewGame(NewGame *);
  void		video(std::string, Manager&);
  void initialize();
  sf::Texture	_background;
  sf::Texture	_bombes[4];
  sf::Texture	_bold[4];
  sf::Sprite	_backS;
  sf::Sprite	_bombe;
  Musique	*_music;
  Musique	*_music2;
  Intro		*_movie;
private:
  sf::RenderWindow app1;
  int		_status;
  Score	*_score;
  Settings	*_settings;
  LoadGame	*_loadgame;
  NewGame	*_newgame;
};

#endif /*MENU_H*/
