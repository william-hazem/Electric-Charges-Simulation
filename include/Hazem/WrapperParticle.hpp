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
    Arrow* acelerationArrow;
    sf::CircleShape particleShape;
    unsigned int id;

    void updateShape();
   
public:
    WrapperParticle();
    WrapperParticle(Particle&, Arrow&, unsigned int);
    ~WrapperParticle();

    // void bind()
    void bind(const Particle&, Arrow*);
    // void create(const CircleShape&);

    void setId(unsigned);
    /// \brief Update the position/angle of Particle and acelerationArrow shape
    void update();

    // GETTERS
    Arrow* getShape() const;
    const sf::CircleShape& getParticleShape() const;
    const Particle& getParticle() const;
};



#endif //!HAZEM_W_PARTICLE