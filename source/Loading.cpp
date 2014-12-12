#include "GameEngine.hpp"


Loading::Loading(std::pair<int, int> pos, std::string name, int size):
   AObject(pos, name, size)
 {
    initialize();
 }

bool Loading::initialize()
 {
    if (_texture.load("./assets/loading.tga") == false)
    {
     std::cerr << "Cannot load the loading texture" << std::endl;
     return (false);
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

void Loading::update(gdl::Clock const &clock, gdl::Input &input)
 {
 }

void Loading::draw(gdl::AShader &shader, gdl::Clock const &clock)
 {
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
 }
