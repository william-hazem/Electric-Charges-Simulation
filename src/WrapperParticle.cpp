#include <Hazem/WrapperParticle.hpp>

WrapperParticle::WrapperParticle() {
    this->acelerationArrow = nullptr;
}

WrapperParticle::WrapperParticle(Particle& particle, Arrow& acelerationArrow, unsigned int id) {
    this->particle = &particle;
    this->acelerationArrow = &acelerationArrow;
    this->id = id;
    this->update();
}

WrapperParticle::~WrapperParticle() {
    this->particle = 0;
    this->acelerationArrow = 0;
}

void WrapperParticle::update() {
    const hz::Vector2& position = particle.getPosition();
    

    particleShape.setPosition( (float) position.x, (float) position.y);

    if(acelerationArrow != nullptr) {
        const hz::Vector2 a = particle.getAceleration().unit();
        const double angle = a.angle();
        this->acelerationArrow->setPosition(particleShape.getPosition());
        this->acelerationArrow->setAngle(90 - angle);
    }
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


void WrapperParticle::bind(const Particle& particle, Arrow* acelerationArrow) {
    this->acelerationArrow = acelerationArrow;
    this->particle = particle;
    
    updateShape();

}



Arrow* WrapperParticle::getShape() const {
    return this->acelerationArrow;
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

// void WrapperParticle::create(const Arrow& arrow) {
//     if(this->particleShape == 0)
//         this->particleShape = new Arrow(arrow);
// }