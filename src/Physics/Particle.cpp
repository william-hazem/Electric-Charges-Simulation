#include <Hazem/Physics/Particle.hpp>

#include <cmath>

float map(float v, float xi, float xf, float yi, float yf) {
    return yi + (v - xi) * (yf - yi) / (xf - xi);
}

const double Particle::radius = 15.f;

float const Particle::fake_eletron_mass       = 9.10938356e-4;
float const Particle::fake_proton_mass        = 1.6726219;

double const Particle::elementary_charge  = 1.602176634e-19; // SI elementary charge
double const Particle::eletron_mass       = 9.10938356e-31;  // SI eleton mass
double const Particle::proton_mass        = 1.6726219e-27;   // SI proton mass
double const Particle::E0                 = 8.85e-12;        // Vacuum permittivity
double const PI = 8.85e-12;

Particle::Particle() {
    init(true);
}

Particle::Particle(const bool& proton) {
    init(proton);
}

Particle::Particle(const float& charge, const hz::Vector2& position) {
    setCharge(charge);
    setPosition(position);
}

Particle::~Particle() {}

void Particle::updateMass() {
    if(signal)
        mass = eletron_mass;
    else
        mass = proton_mass;
}

void Particle::init(bool proton) {
    if(proton) {
        setCharge(elementary_charge);
    }
    else {
        setCharge(elementary_charge * -1);
    }
}


/**
 *  Setters
**/

void Particle::setPosition(const hz::Vector2& position) {
    this->position = position;
}

void Particle::setAceleration(const hz::Vector2& aceleration) {
    this->aceleration = aceleration;
}

void Particle::setVelocity(const hz::Vector2& velocity) {
    this->velocity = velocity;
}

/**
 *  Getters
**/ 

const bool& Particle::getSignal() const {
    return this->signal;
}

const double& Particle::getMass() const {
    return mass;
}

const hz::Vector2& Particle::getPosition() const {
    return this->position;
}

void Particle::setCharge(double charge) {
    this->charge = charge;
    if(charge < 0.0f)
        signal = true;
    else 
        signal = false;
    updateMass();
    
}

const double& Particle::getCharge() const {
    return this->charge;
}

hz::Vector2 Particle::getForce(const Particle& particle) const {

    hz::Vector2 r = this->position - particle.getPosition();
    hz::Vector2 forceVector(0, 0);
    hz::Vector2 direction = r.unit();
    double d = r.abs();

    if (d == 0) return forceVector;
    // double k = 1 / 4 / PI / E0;
    double k = 1 / ( 4 * PI * E0 );

    // double force = (k * this->charge * particle.getCharge()) / (d * d);
    double force(0.0);

    if(this->signal != particle.signal) force = -1000 / d / 2;
    else force = 1000 / d / 2;

    forceVector.x = force * direction.x;
    forceVector.y = force * direction.y;
    return forceVector;
}

hz::Vector2 Particle::getForce(std::vector<Particle>& particles) const{
    hz::Vector2 f;
    for(Particle& i : particles)
        f += this->getForce(i);
    return f;
}

const hz::Vector2& Particle::getAceleration() const {
    return aceleration;
}

const hz::Vector2& Particle::getVelocity() const {
    return velocity;
}

hz::Vector2 Particle::calcForce(const Particle& particle) const {
    hz::Vector2 r = position - particle.getPosition();    
    return r.unit() * ( (charge * particle.getCharge()) 
        / (4 * PI * E0) / pow(r.abs(), 2)
    );
}

hz::Vector2 Particle::calcAceleration(const Particle& particle) const {
    hz::Vector2 force(this->getForce(particle));
    // hz::dec x = force.x;
    // hz::dec y = force.y;
    
    return hz::Vector2(
        force.x / this->signal ? proton_mass : eletron_mass,
        force.y / this->signal ? proton_mass : eletron_mass
    );
}

hz::Vector2 Particle::calcAceleration(std::vector<Particle>& particles) const {
    hz::Vector2 force_sum = this->getForce(particles);
    
    return hz::Vector2(
        force_sum.x / this->signal ? proton_mass : eletron_mass,
        force_sum.y / this->signal ? proton_mass : eletron_mass
    );


}

bool Particle::isProton() const {
    return !signal;
}


void Particle::move(std::vector<Particle>& particles) {
    
    hz::Vector2 f = this->getForce(particles);
    hz::Vector2 other, pos;
    bool canMove = true;
    double dist;

    for(Particle& i : particles) {
        other = i.getPosition();
        pos = this->position - other;
        dist = pos.abs();

        // REACTION FORCE PHASE
        if(dist <= 2*radius) {
            hz::Vector2 fi = this->getForce(i);
            hz::Vector2 normal = pos.unit() * (pos.unit() * fi);
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