#include "WrapperParticle.hpp"

WrapperParticle::WrapperParticle(Particle& particle, Arrow& arrow) {

    this->particle = &particle;
    this->arrow = &arrow;
    this->update();
}

void WrapperParticle::update() {
    const hz::Vector2& position = particle->getPosition();
    this->arrow->setPosition({position.x, position.y});
    printf("ARROW= (%.5f, %.5f)", arrow->getPosition().x, arrow->getPosition().y);


}