//
// AObject.cpp for  in /home/kiril/project/cpp_bomberman/source
//
// Made by Kiril
// Login   <kiril@epitech.net>
//
// Started on  Thu Jun 12 16:20:59 2014 Kiril
// Last update Sun Jun 15 16:30:51 2014 lebeau_c
//


#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <ctime>
#include <glm/gtc/matrix_transform.hpp>
#include "AObject.hpp"
#include "Texture.hh"

AObject::AObject(std::pair<int, int> pos, std::string name, float size, e_object obj):
   _position(pos.first, 0, pos.second),
   _rotation(0, 0, 0),
   _scale(size, size, size),
   _type(obj)
{
  this->_pos = pos;
  this->_name = name;
}

AObject::AObject(AObject const & cpy)
{
  this->_pos = cpy._pos;
  this->_name = cpy._name;
}

AObject::~AObject()
{}

int	AObject::getRand()
{
  int	nb = rand() % 100;
  return (nb);
}

std::string		AObject::getName() const
{
  return (this->_name);
}

int			AObject::checkAObject(AObject *check, std::pair<int, int> value)
{
  for (size_t i = 0; i < check->_lpos.size(); ++i)
    {
      if ((check->_lpos[i].first == value.first && check->_lpos[i].second == value.second))
       return (-1);
   }
   return (0);
}

void			AObject::setBonus(AObject *pos, AObject *bonus, AObject *check)
{
  std::vector<std::pair<float, float> >::iterator it1;
  int	var = 0;
  int	impair = 0;

  for (it1 = pos->_lpos.begin() ; it1 != pos->_lpos.end(); ++it1)
    {
      if (getRand() % 8 == 0 && var == 0 && checkAObject(check, std::make_pair((*it1).first, (*it1).second)) == 0)
	{
	  bonus->_lpos.push_back(std::make_pair((*it1).first, (*it1).second));
	  var++;
	}
      else if (getRand() % 8 == 0 && var != 0)
	{
	  if (var == 3)
	    var = 0;
	  else
	    var++;
	}
      else
	{
	  if (impair == 0 && checkAObject(check, std::make_pair((*it1).first, (*it1).second)) == 0)
	    {
	      bonus->_lpos.push_back(std::make_pair((*it1).first, (*it1).second));
	      impair++;
	    }
	  else if (impair == 3)
	    impair = 0;
	  else
	    {
	      if (checkAObject(check, std::make_pair((*it1).first, (*it1).second)) == 0)
		impair++;
	    }
	}
    }
}


std::pair<float, float>	AObject::getPos() const
{
  return (this->_pos);
}

void			AObject::setName(std::string name)
{
  this->_name = name;
}

void			AObject::setPos(float a, float b)
{
  this->_pos = std::make_pair<float, float> (a, b);
}

bool			AObject::initialize()
{
   return (true);
}

void			AObject::update(gdl::Clock const &clock, gdl::Input &input)
{}

void			AObject::draw(gdl::AShader &shader, gdl::Clock const &clock)
{}

void			AObject::translate(glm::vec3 const &v)
{
   _position += v;
}

void			AObject::translate2(float x, float y)
{
   _position.x += x;
   _position.z += y;
   setPos(_position.x, _position.z);
}


void			AObject::rotate(glm::vec3 const& axis, float angle)
{
   _rotation = axis * angle;
}

void			AObject::rotate_l(glm::vec3 const& axis, float angle)
{
   _rotation += axis * angle;
}

void			AObject::scale(glm::vec3 const& scale)
{
   _scale *= scale;
}

glm::mat4		AObject::getTransformation() const
{
   glm::mat4 transform(1);

   transform = glm::translate(transform, _position);
   transform = glm::scale(transform, _scale);
   transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
   transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
   transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
   return (transform);
}

e_object		AObject::getType() const
{
  return this->_type;
}
