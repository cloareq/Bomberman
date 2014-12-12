//
// ADisplay.cpp for ADisplay in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Thu May 15 21:24:13 2014 lebeau_c
// Last update Wed Jun 11 11:26:04 2014 ledu
//

#include "ADisplay.hpp"

int	ADisplay::getStatut() const
{
   return (_status);
}

void	ADisplay::setStatut(int st)
{
   _status = st;
}

void	ADisplay::setBack(int i)
{
   _back = i;
}

int	ADisplay::getBack() const
{
   return (_back);
}
