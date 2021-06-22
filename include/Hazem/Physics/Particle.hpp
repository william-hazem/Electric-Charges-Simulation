#ifndef HAZEM_PARTICLE
#define HAZEM_PARTICLE

#include <SFML/Graphics.hpp>
#include <Hazem/Util/Vector2.hpp>
#include <vector>

class Particle
{
    // friend class ParticleShape;
private:
    void init(bool);
    double charge;

protected: 

    // Particle position on plane xy
    hz::Vector2 position;
    // Particle aceleration, but its calc with funcs and stored
    hz::Vector2 aceleration;

public:
    static const double radius;
    static double elementary_charge;
    static double eletron_mass;
    static double proton_mass;
    static double E0;

    bool signal;
    
    Particle();
    Particle(bool);
    ~Particle();
    
    void setPosition(const hz::Vector2&);
    void setAceleration(hz::Vector2);
    const hz::Vector2& getPosition() const;
    const double& getCharge() const;
    void setCharge(double);
    
    // GETTERS
    const bool& getSignal() const;
    hz::Vector2 getForce(const Particle&) const;
    hz::Vector2 getForce(std::vector<Particle>&) const;
    hz::Vector2 getAceleration() const;

    /// \brief Calculate force between two particles
    hz::Vector2 calcAceleration(const Particle&) const;
    hz::Vector2 calcAceleration(std::vector<Particle>&) const;
    
    void move(std::vector<Particle>&);
    void move(const Particle&);
    
};

#endif //!HAZEM_PARTICLE