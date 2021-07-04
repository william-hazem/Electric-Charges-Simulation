#include <Hazem/WrapperParticle.hpp>

WrapperParticle::WrapperParticle() {}

WrapperParticle::WrapperParticle(Particle& particle, Arrow& arrowAcceleration, unsigned int id) {
    this->particle = particle;
    this->arrowAcceleration = arrowAcceleration;
    this->id = id;
    this->update();
}

WrapperParticle::~WrapperParticle() {}

void WrapperParticle::update() {

    const hz::Vector2& position = particle.getPosition();

    particleShape.setPosition({(float) position.x, (float) position.y});

    arrowAcceleration.setPosition(particleShape.getPosition());
    arrowAcceleration.setAngle(90 - particle.getVelocity().angle());
}

void WrapperParticle::updateShape() {
    if(particle.getSignal()) {
        particle.setCharge(Particle::elementary_charge);
        particleShape.setFillColor(sf::Color::Green);
    }
    else {
        particle.setCharge(Particle::elementary_charge * -1);
        particleShape.setFillColor(sf::Color::Red);
    }
    particleShape.setRadius(Particle::radius);
    particleShape.setOrigin(sf::Vector2f(Particle::radius, Particle::radius));
}


void WrapperParticle::bind(const Particle& particle) {
    this->arrowAcceleration = Arrow(sf::Vector2f(0, 0), 35.f, 2.5f, sf::Color(0xFAE300CC));
    this->particle = particle;
    
    updateShape();
    update();
}

const Arrow& WrapperParticle::getAccelerationArrow() const {
    return arrowAcceleration;
}

const Particle& WrapperParticle::getParticle() const {
    return particle;
}

const sf::CircleShape& WrapperParticle::getParticleShape() const {
    return particleShape;
}

void WrapperParticle::setId(unsigned int id) {
    this->id = id;
}
