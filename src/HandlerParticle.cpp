#include <Hazem/HandlerParticle.hpp>

HandlerParticle::HandlerParticle() {}

HandlerParticle::~HandlerParticle() {
    this->handler.clear();
}

void HandlerParticle::addParticle(const WrapperParticle& wrapper) {
    this->handler.push_back(wrapper);
}

const WrapperParticle& HandlerParticle::getWrapper(const unsigned int& index) const{
    return handler[index];
}

const Particle& HandlerParticle::getParticle(const unsigned int& index) const {
    return handler[index].particle;
}

hz::Vector2 HandlerParticle::calcE_Force(const Particle& pi) const {
    size_t i, size = this->size();
    std::vector<Particle> particles;

    for(i = 0; i < size; i++) {
        particles.push_back(handler[i].particle);
    }

    hz::Vector2 f, temp;
    for(i = 0; i < size; i++) {
        temp = pi.getForce(particles[i]);
        f.x += temp.x;
        f.y += temp.y;
    }
    particles.clear();
    return f;
}



void HandlerParticle::bindRender(sf::RenderTarget* target) {
    this->target = target;
}

void HandlerParticle::createParticle(const WrapperParticle& wrapper) {
    this->handler.push_back(
        wrapper
    );
}


void HandlerParticle::update() {

    size_t i, size(this->handler.size());
    std::vector<Particle> mutableParticles;
    std::vector<Particle> temp;
    
    // Get all particle inside Wrapper
    for(i = 0; i < size; i++) {
        mutableParticles.push_back(this->handler[i].getParticle());
    }

    // Move
    for(i = 0; i < size; i++) {
        temp = mutableParticles;
        temp.erase(temp.begin() + i);
        // Acessing by Friend Privilegy
        handler[i].particle.move(temp);
        handler[i].update();
    }

}

void HandlerParticle::draw() {
    size_t i, size(this->handler.size());

    for(i = 0; i < size; i++) {
        const WrapperParticle& wp = handler[i]; 

        target->draw(wp.getParticleShape());
        // if(wp.acelerationArrow != nullptr)
        //     target->draw(*wp.acelerationArrow);
        // printf("[DRAW] Position: %f, %f\n", particle.getPosition().x, 
        // particle.getPosition().y);
    }
}

size_t HandlerParticle::size() const {
    return handler.size();
}