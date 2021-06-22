#include <Hazem/HandlerParticle.hpp>

HandlerParticle::HandlerParticle() {}

HandlerParticle::~HandlerParticle() {
    this->handler.clear();
}

void HandlerParticle::addParticle(const WrapperParticle& wrapper) {
    this->handler.push_back(wrapper);
    const Particle p = this->handler.back().getParticle();
    printf("[ADDED] position: %f,%f\n",p.getPosition().x, p.getPosition().y);
}

const WrapperParticle& HandlerParticle::getWrapper(const unsigned int& index) const{
    return this->handler[index];
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
    std::vector<Particle> mutableParticles, temp;
    
    for(i = 0; i < size; i++) {
        mutableParticles.push_back(this->handler[i].getParticle());
    }


    for(i = 0; i < size; i++) {
        temp = mutableParticles;
        temp.erase(temp.begin() + i);
        // Acessing by Friend Privilegy
        this->handler[i].particle.move(temp);
        handler[i].update();
    }

}

void HandlerParticle::draw() {
    this->update();
    size_t i, size(this->handler.size());

    for(i = 0; i < size; i++) {
        const WrapperParticle& wp = handler[i]; 

        target->draw(wp.getParticleShape());
        // printf("[DRAW] Position: %f, %f\n", particle.getPosition().x, 
        // particle.getPosition().y);
    }
}

size_t HandlerParticle::size() const {
    return this->handler.size();
}