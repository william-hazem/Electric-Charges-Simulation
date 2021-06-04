#ifndef HAZEM_W_PARTICLE
#define HAZEM_W_PARTICLE


#include "Physics/Particle.hpp"
#include "graphics/Shapes/Arrow.hpp"

class WrapperParticle
{
private:
    Particle* particle;
    Arrow* arrow;

   
public:
    WrapperParticle(Particle&, Arrow&);
    ~WrapperParticle();

    void update();
};



#endif //!HAZEM_W_PARTICLE