#include <Hazem/HandlerParticle.hpp>

#include <thread>

std::mutex HandlerParticle::mutex;

HandlerParticle::HandlerParticle() {}

HandlerParticle::~HandlerParticle() {
    this->handler.clear();
}

void HandlerParticle::addParticle(const WrapperParticle& wrapper) {
    handler.push_back(wrapper);
}

const WrapperParticle& HandlerParticle::getWrapper(const unsigned int& index) const{
    return handler[index];
}

const Particle& HandlerParticle::getParticle(const unsigned int& index) const {
    return handler[index].particle;
}

hz::Vector2 HandlerParticle::calcE_Force_fake(const Particle& pi) const {
    size_t i, size = this->size();
    
    hz::Vector2 f;
    for(i = 0; i < size; i++) {
        f += pi.getForce(handler[i].particle);
    }
    return f;
}

hz::Vector2 HandlerParticle::calcEForce(const Particle& p) const {
    hz::Vector2 f;
    for(const WrapperParticle& i : handler) {
        f += p.calcForce(i.particle);
    }
    // f = kg pixel / s^2 -> kg m / s^2
    return f;
}

void HandlerParticle::bindRender(sf::RenderTarget* target) {
    this->target = target;
}

void HandlerParticle::createParticle(const WrapperParticle& wrapper) {
    handler.push_back(wrapper);
}

void HandlerParticle::clear() {
    handler.clear();
}

void HandlerParticle::updateField(Arrow* begin, Arrow* end) const{
    mutex.lock();
    std::vector<WrapperParticle> handler = this->handler;
    mutex.unlock();

    Particle p;
    printf("started updateField: %d\n", std::this_thread::get_id());
    while(begin != end) {
        hz::Vector2 f;  
        p.setPosition(hz::Vector2(begin->getPosition().x, begin->getPosition().y));
        // f = calcEForce(p);
        for(WrapperParticle& wp : handler) {
            f += p.calcForce(wp.particle);
        }
        begin->setAngle(90 - f.angle());
        begin++;
    }
}

void updateField2(Arrow* begin, Arrow* end, std::vector<WrapperParticle> handler) {
    Particle p;
    // std::lock_guard<std::mutex> lock(mutex);
    while(begin != end) {
        hz::Vector2 f;  
        p.setPosition(hz::Vector2(begin->getPosition().x, begin->getPosition().y));
        for(WrapperParticle& wp : handler) {
            f += p.calcForce(wp.getParticle());
        }
        begin->setAngle(90 - f.angle());
        begin++;
    }
}

void HandlerParticle::update(const bool& upParticle, const bool& upField
    , std::vector<Arrow>& field, const float& t, const bool& bordered) {

    if(!(upParticle || upField)) {
        return; //not need update
    }

    Particle* ptrParticle;
    size_t i, j, size = handler.size();

    if(upParticle) {
        // update all particles
        for(i = 0; i < size; i++) {
            ptrParticle = &(handler[i].particle);
            hz::Vector2 f, fi, pos, newPos;
            // calcule the result force in particle i
            for(j = 0; j < size; j++) {
                if(i != j) {
                    fi = ptrParticle->calcForce(handler[j].particle);
                    pos = ptrParticle->getPosition() - handler[j].particle.getPosition();
                    // Calcule normal force on particles contact
                    if( pos.abs() <= 2*ptrParticle->radius ) {
                        // Destribuição da força sobre o vetor r (FORÇA NORMAL)
                        f -= pos.unit() * (pos.unit() * fi);
                        // totalmente ineslatico
                        ptrParticle->setVelocity(hz::Vector2(0, 0));
                    }
                    
                    f += fi;
                    
                }
            }   //!for loop j

            // calcule the aceleration pixel / second
            // 100 pixels = 1 m
            // 1km = 1000m
            ptrParticle->setAceleration(f / ptrParticle->getMass() / 1e6); 
            ptrParticle->setVelocity( ptrParticle->getVelocity() +
                ptrParticle->getAceleration() * t);
            // move the particle
            newPos = ptrParticle->getPosition() + 
                ptrParticle->getVelocity()*t +
                ptrParticle->getAceleration() * t * t / 2;
            // has border limit?
            if(bordered) {
                if(newPos.y <= 0 || newPos.y >= target->getSize().y) {
                    hz::Vector2 a = ptrParticle->getVelocity();
                    a.y = a.y * -1;
                    ptrParticle->setVelocity(a);
                }
                if(newPos.x <= 0 || newPos.x >= target->getSize().x) {
                    hz::Vector2 a = ptrParticle->getVelocity();
                    a.x = a.x * -1;
                    ptrParticle->setVelocity(a);
                }
            }
            ptrParticle->setPosition(newPos);
            handler[i].update();
        }// !for i loop 
    }// !updateParticle

    if(upField && size) {
        size_t spo = field.size() / 4;
        Arrow* begin1 = field.data();
        Arrow* begin2 = field.data() + spo;
        Arrow* begin3 = field.data() + 2*spo;
        Arrow* begin4 = field.data() + 3*spo;
        Arrow* end = field.data() + field.size();

        // std::thread threads[] = {
        //     std::thread(&HandlerParticle::updateField, *this, begin1, (begin1 + spo)),
        //     std::thread(&HandlerParticle::updateField, *this, begin2, (begin2 + spo)),
        //     std::thread(&HandlerParticle::updateField, *this, begin3, (begin3 + spo)),
        //     std::thread(&HandlerParticle::updateField, *this, begin4, (begin4 + (field.size() - 3*spo)))

        // };
        // for(int i = 0; i < 4; i++) {
        //     threads[i].join();
        // }
        std::thread t1(&HandlerParticle::updateField, this, begin1, end);
        t1.join();
    }


}

void HandlerParticle::draw(const bool& drawArrow) {
    size_t i, size(handler.size());

    for(i = 0; i < size; i++) {
        target->draw(handler[i].particleShape);
        if(drawArrow) {
            target->draw(handler[i].arrowAcceleration);
        }
    }
}

size_t HandlerParticle::size() const {
    return handler.size();
}

/// Operator
WrapperParticle& HandlerParticle::operator[](const size_t& index) {
    return handler[index];
}