#ifndef HAZEM_PARTICLE
#define HAZEM_PARTICLE

#include <SFML/Graphics.hpp>
#include "../util/Vector2.hpp"
#include <cmath>
#include <vector>

class Particle
{
    // friend class ParticleShape;
private:
    sf::CircleShape shape;
    void init(bool);
    double charge;
    static double radius;

protected: 
    hz::Vector2 aceleration;
    hz::Vector2 position;
    

public:
    static double elementary_charge;
    static double eletron_mass;
    static double proton_mass;
    static double E0;

    bool signal;
    
    Particle(bool);
    ~Particle();
    
    void setPosition(hz::Vector2 position);
    void setAceleration(hz::Vector2);
    const hz::Vector2& getPosition() const;
    const double& getCharge() const;
    void setCharge(double);
    

    sf::CircleShape getShape() const;
    hz::Vector2 getForce(const Particle&) const;
    hz::Vector2 getForce(std::vector<Particle>&) const;
    hz::Vector2 getAceleration(const Particle&) const;
    hz::Vector2 getAceleration(std::vector<Particle>&) const;
    
    void move(std::vector<Particle>&);
    void move(const Particle&);
    
};

#endif //!HAZEM_PARTICLE