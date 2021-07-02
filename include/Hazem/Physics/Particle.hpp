#ifndef HAZEM_PHYSICS_PARTICLE_H
#define HAZEM_PHYSICS_PARTICLE_H

#include <SFML/Graphics.hpp>
#include <Hazem/Util/Vector2.hpp>
#include <vector>

class Particle
{
    void init(bool);
    static const float fake_eletron_mass;
    static const float fake_proton_mass;

    /// \brief call to define if its will use proton mass or eletron one
    void updateMass();
protected: 

    // Particle position on plane xy
    hz::Vector2 position;
    // Particle aceleration, but its calc with funcs and stored
    hz::Vector2 aceleration;
    // Particle velocity
    hz::Vector2 velocity;

    double mass;
    double charge;

public:
    static const double radius;
    static const double elementary_charge;
    static const double eletron_mass;
    static const double proton_mass;
    static const double E0;

    bool signal;
    
    Particle();
    Particle(const bool&);
    Particle(const float&, const hz::Vector2&);
    ~Particle();
    
    //SETTERS
    void setPosition(const hz::Vector2&);
    void setAceleration(const hz::Vector2&);
    void setVelocity(const hz::Vector2&);
    const hz::Vector2& getPosition() const;
    const double& getCharge() const;
    void setCharge(double);
    
    // GETTERS
    const bool& getSignal() const;
    const double& getMass() const;
    hz::Vector2 getForce(const Particle&) const;
    hz::Vector2 getForce(std::vector<Particle>&) const;
    const hz::Vector2& getAceleration() const;
    const hz::Vector2& getVelocity() const;
    /// \brief Calculate force between two particles
    hz::Vector2 calcForce(const Particle&) const;
    hz::Vector2 calcAceleration(const Particle&) const;
    hz::Vector2 calcAceleration(std::vector<Particle>&) const;

    bool isProton() const;

    void move(std::vector<Particle>&);
    void move(const Particle&);
    
};

#endif //!HAZEM_PARTICLE