// Thread.hpp for  in /home/kiril/rendu/cpp_plazza
//
// Made by Kiril
// Login   <kiril@epitech.net>
//
// Started on  Tue Jun 10 15:38:31 2014 Kiril
// Last update Wed Jun 11 01:40:44 2014 Kiril
//

#ifndef	_THREAD_HH_
#define	_THREAD_HH_

#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>

class	Thread
{
public:
  Thread(pthread_attr_t *, void *(*) (void *), void *);
  ~Thread();
  void	myCreate(const pthread_attr_t *, void *(*) (void *), void *);
  void	myJoin();
  void	myExit();
private:
  pthread_t	th;
};

#endif
