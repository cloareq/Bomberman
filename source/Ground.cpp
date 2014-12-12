#include "GameEngine.hpp"
//#include "Ground.hpp"

Ground::Ground(std::pair<int, int> pos, std::string name, int size):
   AObject(pos, name, size)
 {
    initialize();
 }

bool Ground::initialize()
 {
    if (_texture.load("./assets/sol.tga") == false)
    {
       std::cerr << "Cannot load the cube texture" << std::endl;
       return (false);
    }
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();
    return (true);
}

void Ground::update(gdl::Clock const &clock, gdl::Input &input)
 {

 }

void Ground::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
 }
