//
// ADisplay.hpp for ADisplay in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 12:01:52 2014 lebeau_c
// Last update Sun Jun 15 12:19:57 2014 lebeau_c
//

#ifndef ADISPLAY_H
#define ADISPLAY_H

#include "Manager.hpp"

class ADisplay
{
public:
   static ADisplay	&instance();
   void			refresh_mouse(sf::Event);
   void			draw(Manager &);
   int			getStatut() const;
   void			setStatut(int);
   int			getBack() const;
   void			setBack(int);

protected:
   static ADisplay	m_instance;
   int			_mouseX;
   int			_mouseY;
   int			_status;
   int			_back;
   sf::Font		_font;
   sf::Text		_text;
   ADisplay(){}
   ~ADisplay(){}
};

#endif /*ADISPLAY_H*/
