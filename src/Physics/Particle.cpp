#include <Hazem/Physics/Particle.hpp>

double Particle::radius = 15.f;

double Particle::elementary_charge  = 1.602176634e-19;
// double Particle::elementary_charge  = 1.602176634;
// double Particle::eletron_mass       = 9.10938356e-31;
double Particle::eletron_mass       = 9.10938356;
double Particle::proton_mass        = 1.6726219e-27;
double Particle::E0                 = 8.85e-12;
double PI = 8.85e-12;

Particle::Particle(bool positive = true) {
    this->signal = positive;
    init(positive);
}

Particle::~Particle() {
    
}

void Particle::init(bool positive) {
    
    if(positive) {
        this->charge = elementary_charge;
        shape.setFillColor(sf::Color::Green);
    }
    else {
        this->charge = elementary_charge * (-1);
        shape.setFillColor(sf::Color::Red);
    }
    shape.setRadius(this->radius);
    shape.setOrigin(sf::Vector2f(this->radius, this->radius));
    this->aceleration = hz::Vector2(0, 0);
}


/**
 *  Setters
**/

void Particle::setPosition(hz::Vector2 position) {
    this->position = position;
    this->shape.setPosition(sf::Vector2f(position.x, position.y));
}

void Particle::setAceleration(hz::Vector2 aceleration) {
    this->aceleration = aceleration;
}

/**
 *  Getters
**/ 

sf::CircleShape Particle::getShape() const {
    return this->shape;
};

const hz::Vector2& Particle::getPosition() const {
    return this->position;
}

void Particle::setCharge(double charge) {
    this->charge;
}

const double& Particle::getCharge() const {
    return this->charge;
}

hz::Vector2 Particle::getForce(const Particle& particle) const{

    hz::Vector2 r = this->position - particle.getPosition();
    hz::Vector2 forceVector(0, 0);
    hz::Vector2 direction = r.unit();
    double d = r.abs();

    if (d == 0) return forceVector;
    // double k = 1 / 4 / PI / E0;
    double k = 1 / ( 4 * PI * E0 );

    // double force = (k * this->charge * particle.getCharge()) / (d * d);
    double force(0.0);

    if(this->signal != particle.signal) force = -1000 / d / d;
    else force = 1000 / d / d;

    forceVector.x = force * direction.x;
    forceVector.y = force * direction.y;
    return forceVector;
}

hz::Vector2 Particle::getForce(std::vector<Particle>& particles) const{

    hz::Vector2 total_force, fi;


    for(Particle& i : particles) {
        fi = this->getForce(i);
        total_force.x += fi.x;
        total_force.y += fi.y;
        
    }
    // printf("Total_force - %.15f", total_force.x);
    return total_force;
}

hz::Vector2 Particle::getAceleration() const {
    return this->aceleration;
}

hz::Vector2 Particle::calcAceleration(const Particle& particle) const {
    hz::Vector2 force(this->getForce(particle));
    // hz::dec x = force.x;
    // hz::dec y = force.y;
    
    return hz::Vector2(
        force.x / eletron_mass,
        force.y / eletron_mass
    );
}

hz::Vector2 Particle::calcAceleration(std::vector<Particle>& particles) const {
    hz::Vector2 force_sum = this->getForce(particles);
    
    return hz::Vector2(
        force_sum.x / eletron_mass,
        force_sum.y / eletron_mass
    );


}

void Particle::move(std::vector<Particle>& particles) {
    
    hz::Vector2 f = this->getForce(particles);
    
    
    hz::Vector2 other, pos;
    bool canMove = true;
    double dist;

    for(Particle i : particles) {
        other = i.getPosition();
        pos = this->position - other;
        dist = pos.abs();

        // REACTION FORCE PHASE
        if(dist <= 2*radius) {
            // canMove = false;
            
            
            // Destribuição da força sobre o vetor r (FORÇA NORMAL)
            hz::Vector2 normal = (pos.unit()*(hz::dec)(pos.unit() * f));
            printf("Force: %.10f, %.10f\n", f.x, f.y);
            printf("NORMAL FORCE: %.10f, %.10f\n", normal.x, normal.y);
            f.x -= normal.x;
            f.y -= normal.y;
        }
        
    }

    hz::Vector2 a = f / eletron_mass;
    this->setAceleration(hz::Vector2(a));
    // New Position
    double x = this->position.x + a.x;
    double y = this->position.y + a.y;

    if(canMove) {
        // printf("Can move\n");
        // printf("Aceleration: %.*f - %.*f\n", a.x, a.y);
        
        this->setPosition(hz::Vector2(x, y));
    }

    
}

void Particle::move(const Particle& particle) {

    hz::Vector2 force = this->calcAceleration(particle);
    hz::Vector2 newPosition = this->position + force;
    double r = hz::Vector2(this->position - particle.position).abs();
    
    if(newPosition.x < 0) newPosition.x = newPosition.x * -1;
    if(newPosition.y < 0) newPosition.y = newPosition.y * -1;

    if(r <= 2*radius) {

    }
    else {
        this->setPosition(newPosition);
    }



}