#include "GameEngine.hpp"


Ending::Ending(std::pair<int, int> pos, std::string name, int size, int choice):
   AObject(pos, name, size)
 {
    initialize(choice);
 }

bool Ending::initialize(int choice)
 {
 	if (choice == 1)
 	{
 		if (_texture.load("./assets/loose.tga") == false)
 		{
 			std::cerr << "Cannot load the loading texture" << std::endl;
 			return (false);
 		}
 	}
 	else
 	{
 		if (_texture.load("./assets/ialoose.tga") == false)
 		{
 			std::cerr << "Cannot load the loading texture" << std::endl;
 			return (false);
 		}
 	}
 _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
 _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
 _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
 _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
 _geometry.pushUv(glm::vec2(0.0f, 0.0f));
 _geometry.pushUv(glm::vec2(1.0f, 0.0f));
 _geometry.pushUv(glm::vec2(1.0f, 1.0f));
 _geometry.pushUv(glm::vec2(0.0f, 1.0f));
 _geometry.build();
 return (true);
}

void Ending::update(gdl::Clock const &clock, gdl::Input &input)
 {
 }

void Ending::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
 }
