//
// SaveMap.cpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Sat Jun 14 15:23:04 2014 Antoine BERGHEN
// Last update Sun Jun 15 00:56:43 2014 Antoine BERGHEN
//

#include "SaveMap.hpp"

SaveMap::SaveMap(std::vector<AObject *> & obj)
{
  this->_obj = obj;
  this->_val = 1;
  this->OpenMapAndWrite();

}

SaveMap::~SaveMap()
{

}

void	SaveMap::OpenMap()
{
  this->ofs.open (".save", std::ofstream::out | std::ofstream::app);
}

void	SaveMap::WriteInFile()
{
  this->ofs << this->_val << std::endl;

  for (size_t i = 0; i < this->_obj.size(); ++i)
    {
      this->ofs << this->_obj[i]->getName() << std::endl;
      if (this->_obj[i]->getName().compare("Player") != 0)
	{
	  for (size_t j = 0; j < this->_obj[i]->_lpos.size(); ++j)
	    this->ofs << this->_obj[i]->_lpos[j].first << "-" << this->_obj[i]->_lpos[j].second << std::endl;
	}
      else
	this->ofs << this->_obj[i]->getPos().first << "-" << this->_obj[i]->getPos().second << std::endl;
    }
      //      std::cout << this->_obj[i]->getName() << std::endl;
  // while (this->_obj[i])
  //   {
  //     std::cout << this->_obj[i]->getName() << std::endl;
  //     i++;
  //   }
}

void	SaveMap::OpenMapAndWrite()
{
  this->OpenMap();
  this->WriteInFile();
}
