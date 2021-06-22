#ifndef HAZEM_HANDLER_PARTICLE
#define HAZEM_HANDLER_PARTICLE

#include <Hazem/WrapperParticle.hpp>
#include <vector>


class HandlerParticle
{
private:
    std::vector<WrapperParticle> handler;
    sf::RenderTarget* target;
public:
    HandlerParticle();
    ~HandlerParticle();
    
    void addParticle(const WrapperParticle&);
    void bindRender(sf::RenderTarget*);
    
    void createParticle(const WrapperParticle&);
    const WrapperParticle& getWrapper(const unsigned int&) const;

    size_t size() const;



    void update();
    void draw();
};

#endif //!HAZEM_HANDLER_PARTICLE
