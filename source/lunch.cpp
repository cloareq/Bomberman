//
// lunch.cpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Tue Jun  3 10:38:50 2014 Antoine BERGHEN
// Last update Sun Jun 15 12:09:38 2014 lebeau_c
//

#include <cstdlib>
#include <pthread.h>
#include <iostream>
#include <Texture.hh>
#include <Model.hh>
#include <Geometry.hh>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GameEngine.hpp"
#include "Thread.hpp"

void	*launch(void *arg)
{
  GameEngine engine((Manager*)arg);
   if (engine.initialize() == false)
      return (NULL);
   while (engine.update() == true)
      engine.draw();
   ((Manager*)arg)->setAlreadyLaunch(0);
   pthread_exit(NULL);
}

int lunch(Manager & manag)
{
   manag.setThread(new Thread(NULL, &launch, &manag));

   return (0);
}
