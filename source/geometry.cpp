//
// geometry.cpp for  in 
// 
// Made by Antoine BERGHEN
// Login   <berghe_a@epitech.net>
// 
// Started on  Tue Jun  3 10:38:04 2014 Antoine BERGHEN
// Last update Tue Jun  3 10:38:05 2014 Antoine BERGHEN
//

#include "GameEngine.hpp"

gdl::Geometry	create_cube()
{
   gdl::Geometry _geometry;

   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
   _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
   _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));

   _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
   _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
   _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

   _geometry.pushUv(glm::vec2(0.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 0.0f));
   _geometry.pushUv(glm::vec2(1.0f, 1.0f));
   _geometry.pushUv(glm::vec2(0.0f, 1.0f));
   _geometry.build();
   return (_geometry);
}
