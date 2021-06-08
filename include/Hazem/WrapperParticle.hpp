#ifndef HAZEM_W_PARTICLE
#define HAZEM_W_PARTICLE

#include "Physics/Particle.hpp"
#include "graphics/Shapes/Arrow.hpp"

class WrapperParticle
{
private:
    Particle* particle;
    Arrow* arrow;
    unsigned int id;
   
public:
    WrapperParticle();
    WrapperParticle(Particle&, Arrow&, unsigned int);
    ~WrapperParticle();


    void bind(Particle*, Arrow*);
    void bindRender(sf::RenderTarget*);

    void setId(unsigned);

    void update();
    Arrow* getShape() const;
};



#endif //!HAZEM_W_PARTICLE