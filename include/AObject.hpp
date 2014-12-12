//
// AObject.hpp for  in
//
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
//
// Started on  Tue Jun  3 10:34:05 2014 Antoine BERGHEN
// Last update Sun Jun 15 12:57:28 2014 Kiril
//

#pragma once

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Texture.hh"
#include "AShader.hh"
#include "Manager.hpp"
#include "enum.h"

class AObject
{
public:
  AObject(std::pair<int, int>, std::string, float size, e_object obj = NOTHING);
  AObject(AObject const &);
  virtual ~AObject();

  std::string			getName() const;
  void				setName(std::string);
  std::pair<float, float>	getPos() const;

  virtual bool			initialize();
  virtual void			update(gdl::Clock const &clock, gdl::Input &input);
  virtual void			draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;

  int				checkAObject(AObject *, std::pair <int, int>);
  void				setBonus(AObject *, AObject *, AObject *);
  glm::mat4			getTransformation() const;
  void				scale(glm::vec3 const& scale);
  void				rotate(glm::vec3 const& axis, float angle);
  void				rotate_l(glm::vec3 const& axis, float angle);
  void				translate(glm::vec3 const &v);
  void				translate2(float x, float y);
  int				getRand();
  void				setPos(float, float);
  e_object			getType() const;
  std::vector<std::pair<float, float> >	_lpos;

protected:
  Manager				*_manager;
  std::pair<int, int>			_pos;
  std::string				_name;
  glm::vec3				_position;
  glm::vec3				_rotation;
  glm::vec3				_scale;
  e_object				_type;
};
