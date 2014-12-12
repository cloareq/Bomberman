//
// ParsMapSecond.hpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Wed Jun 11 10:51:14 2014 Antoine BERGHEN
// Last update Wed Jun 11 10:56:16 2014 Antoine BERGHEN
//

#ifndef PARSMAPSECOND_HPP
#define PARSMAPSECOND_HPP

#include <iostream>

class ParsMapSecond
{
public:
  ParsMapSecond(std::string);
  ~ParsMapSecond();
  void	PutShortName(std::string);
  std::string	getShortName() const;

private:
  std::string	_ShortName;
};


#endif
