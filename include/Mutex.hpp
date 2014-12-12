//
// Mutex.hpp for hello in /home/ledu/projet/cpp_plazza/includes
// 
// Made by ledu
// Login   <ledu@epitech.net>
// 
// Started on  Fri Apr 25 10:24:12 2014 ledu
// Last update Sun Apr 27 20:50:53 2014 Kiril
//

#ifndef	_MUTEX_HH_
#define	_MUTEX_HH_

#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>

class	Mutex
{
private:
  pthread_mutex_t	_mutex;
public:
  Mutex();
  ~Mutex();
  int	lock();
  int	trylock();
  int	unlock();
  int	destroy();
};

#endif
