//
// SaveMap.hpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Sat Jun 14 15:12:06 2014 Antoine BERGHEN
// Last update Sat Jun 14 15:45:19 2014 Antoine BERGHEN
//

#ifndef SAVEMAP_HPP
#define SAVEMAP_HPP

#include "AObject.hpp"
#include <fstream>

class SaveMap
{
public:
  SaveMap(std::vector<AObject *> &);
  ~SaveMap();
  void	OpenMap();
  void	OpenMapAndWrite();
  void	WriteInFile();
  
  
private:
  std::vector<AObject *>  _obj;
  std::ofstream ofs;
  int _val;

};

#endif
