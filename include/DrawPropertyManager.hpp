//
// DrawPropertyManager.hpp for DrawPM in /home/lebeau_c/Projects/cpp_bomberman/Menu
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Tue May 13 16:03:04 2014 lebeau_c
// Last update Tue May 13 16:07:33 2014 lebeau_c
//

#ifndef DRAWPROPERTYMANAGER_H
#define DRAWPROPERTYMANAGER_H

#include <iostream>
#include <string>

class DPM
{
public:
   DPM();
   ~DPM();
   void addProperty();
   void getProperty();

private:
   std::map<std::string, std::pair<int, int>>;
};

#endif /*DRAWPROPERTYMANAGER_H*/
