//
// error_end.cpp for  in /home/berghe_a/tek2/projet/c++/cpp_plazza/sources
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Sat Apr 26 14:56:20 2014 Antoine BERGHEN
// Last update Sat Apr 26 15:02:13 2014 Antoine BERGHEN
//

#include "error.hpp"

void	error_end(const char *str)
{
  std::cerr << str << std::endl;
  exit(1);
}
