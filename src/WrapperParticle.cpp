#include <Hazem/WrapperParticle.hpp>

WrapperParticle::WrapperParticle() {
    this->arrow = nullptr;
    this->particle = nullptr;
}
WrapperParticle::WrapperParticle(Particle& particle, Arrow& arrow, unsigned int id) {

    this->particle = &particle;
    this->arrow = &arrow;
    this->id = id;
    this->update();
}

WrapperParticle::~WrapperParticle() {
    this->particle = 0;
    this->arrow = 0;
}

void WrapperParticle::update() {
    const hz::Vector2& position = particle->getPosition();
    const hz::Vector2 a = particle->getAceleration().unit();
    const double angle = a.angle();
    this->arrow->setPosition({position.x, position.y});
    this->arrow->setAngle(90 - angle);

    
    // printf("Angle = %.5f\n", angle);
    // printf("ARROW= (%.5f, %.5f)\n", a.x, a.y);
    // printf("POSITION = (%.5f, %.5f)\n",position.x, position.y);
}

void WrapperParticle::bind(Particle* particle, Arrow* arrow) {
    this->arrow = arrow;
    this->particle = particle;
}

void WrapperParticle::bindRender(sf::RenderTarget* render) {
    
}

Arrow* WrapperParticle::getShape() const {
    return this->arrow;
}

void WrapperParticle::setId(unsigned int id) {
    this->id = id;
}