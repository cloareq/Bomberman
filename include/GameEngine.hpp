//
// GameEngine.hpp for GameEngine in /home/lebeau_c/Projects/cpp_bomberman/include
//
// Made by lebeau_c
// Login   <lebeau_c@epitech.net>
//
// Started on  Mon Jun  2 15:30:29 2014 lebeau_c
// Last update Sun Jun 15 19:21:13 2014 lebeau_c
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#pragma once

//#include "IA.hpp"

#include <vector>
#include <SdlContext.hh>
#include "AShader.hh"
#include "AObject.hpp"
#include "BasicShader.hh"
#include "Cube.hpp"
//#include "IA.hpp"
#include "Wall.hpp"
#include "Game.hh"
#include "Fire.hpp"
#include "Dynamite.hpp"
#include "SaveMap.hpp"
#include "Ground.hpp"
#include "Pp1.hpp"
#include "Pp2.hpp"
#include "Loading.hpp"
#include "Manager.hpp"
#include "Ending.hpp"

#define CAM_X	0.0
#define CAM_Y	10.0
#define CAM_Z	5.0
#define SIZE_X	1920
#define SIZE_Y	1080

class Player;
class ia;

class GameEngine : public gdl::Game
{
public:
  GameEngine(Manager *manager);
  ~GameEngine();
  bool			initialize();
  bool			update();
  void			draw();
  void			initIa();
  void			loadingScreen();
  void			zoomCam();
  void			deZoomCam();
  void			updateCam();
  void			rotateCam(int, int);
  bool			deadPlayer();
  std::pair<int, int>	getPosPlayer(std::pair<int, int> pos);
  AObject *		getObjByPos(std::pair<int, int>) const;
  std::vector<AObject*> getObj() const;
  gdl::SdlContext	getContext() const;
  gdl::Clock &		getClock();
  gdl::BasicShader &	getShader();
  void			cleanObj();
  void			Loose(int);
   void			affPicture(AObject *);

private:
  gdl::SdlContext		_context;
  gdl::Clock			_clock;
  gdl::Input			_input;
  gdl::BasicShader		_shader;
  std::string			_map;
  std::vector<AObject*>		_obj;
  std::vector<ia*>		_lia;
  float				_camX;
  float				_camY;
  float				_camZ;
  float				_corecX;
  float				_corecZ;
  e_object			_type;
  ia				*_ia;
  int				_nbPlayer;
  bool _endProgram;
  int				_nbia;
};

#endif /*GAMEENGINE_H*/
