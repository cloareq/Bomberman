//
// ParsMapSecond.cpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Wed Jun 11 10:52:03 2014 Antoine BERGHEN
// Last update Wed Jun 11 14:38:59 2014 ledu
//

#include "ParsMapSecond.hpp"

ParsMapSecond::ParsMapSecond(std::string name)
{
  this->PutShortName(name);
}

ParsMapSecond::~ParsMapSecond()
{

}

void	ParsMapSecond::PutShortName(std::string name)
{
  int	i = 0;
  const char *cpy = name.c_str();

  while (cpy[i] && cpy[i] != '.' && i < 8)
    i++;
  this->_ShortName = name.substr(0, i);
}

std::string ParsMapSecond::getShortName() const
{
  return (this->_ShortName);
}
