//
// Mutex.cpp for hello in /home/ledu/projet/cpp_plazza/srcs
// 
// Made by ledu
// Login   <ledu@epitech.net>
// 
// Started on  Fri Apr 25 15:03:13 2014 ledu
// Last update Sun Apr 27 20:53:38 2014 Kiril
//

#include "Mutex.hpp"

Mutex::Mutex()
{
  this->_mutex = PTHREAD_MUTEX_INITIALIZER;
}

Mutex::~Mutex()
{
  this->destroy();
}

int	Mutex::destroy()
{
  return pthread_mutex_destroy(&this->_mutex);
}

int	Mutex::lock()
{
  return pthread_mutex_lock(&this->_mutex);
}

int	Mutex::trylock()
{
  return pthread_mutex_lock(&this->_mutex);
}

int	Mutex::unlock()
{
  return pthread_mutex_unlock(&this->_mutex);
}
