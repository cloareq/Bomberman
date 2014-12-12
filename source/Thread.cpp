//
// Thread.cpp for  in /home/kiril/rendu/cpp_plazza
//
// Made by Kiril
// Login   <kiril@epitech.net>
//
// Started on  Tue Jun 10 15:37:46 2014 Kiril
// Last update Wed Jun 11 01:41:14 2014 Kiril
//

#include "Thread.hpp"

Thread::Thread(pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
  this->myCreate(attr, start_routine, arg);
}

Thread::~Thread()
{
  this->myExit();
}

void	Thread::myCreate(const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
  try
    {
      if (pthread_create(&(this->th), attr, start_routine, arg) != 0)
	throw std::string("Error on pthread_create");
    }
  catch(std::string const& chaine)
    {
      std::cerr << chaine << std::endl;
    }
}

void	Thread::myJoin()
{
  try
    {
      if (pthread_join(this->th, NULL) != 0)
	throw std::string("Error on pthread join");
    }
  catch(std::string const& chaine)
    {
      std::cerr << chaine << std::endl;
    }
}

void	Thread::myExit()
{
  pthread_exit(NULL);
}
