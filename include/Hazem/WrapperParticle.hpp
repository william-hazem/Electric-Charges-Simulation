#ifndef HAZEM_W_PARTICLE
#define HAZEM_W_PARTICLE

#include "Physics/Particle.hpp"
#include "graphics/Shapes/Arrow.hpp"

#include <vector>

class WrapperParticle
{
    friend class HandlerParticle;
private:
    Particle particle;
    Arrow arrowAcceleration;
    sf::CircleShape particleShape;
    unsigned int id;

    void updateShape();
   
public:
    WrapperParticle();
    WrapperParticle(Particle&, Arrow&, unsigned int);
    ~WrapperParticle();

    void bind(const Particle&);

    void setId(unsigned);
    /// \brief Update the position/angle of Particle and acelerationArrow shape
    void update();

    // GETTERS
    const Arrow& getAccelerationArrow() const;
    const sf::CircleShape& getParticleShape() const;
    const Particle& getParticle() const;

    

};



#endif //!HAZEM_W_PARTICLE