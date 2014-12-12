//
// Music.hpp for hello in /home/ledu/projet/cpp_bomberman/Menu
//
// Made by ledu
// Login   <ledu@epitech.net>
//
// Started on  Fri May 30 15:26:43 2014 ledu
// Last update Sun Jun  8 18:17:14 2014 lebeau_c
//

#ifndef	MUSIC_HPP_
#define	MUSIC_HPP_

#include <SFML/Audio.hpp>

class	Musique
{
public :
  Musique();
  ~Musique();
  void	openFromFile(std::string);
  void	Play();
  void	Pause();
   void	SetVolume(double);

private :
  sf::Music *_mus;
};

#endif
