#ifndef HAZEM_HANDLER_PARTICLE
#define HAZEM_HANDLER_PARTICLE

#include <Hazem/WrapperParticle.hpp>
#include <vector>
#include <mutex>


class HandlerParticle
{
    std::vector<WrapperParticle> handler;
    sf::RenderTarget* target;

    void updateField(Arrow*, Arrow*) const;
    static std::mutex mutex;

public:
    HandlerParticle();
    ~HandlerParticle();
    
    void addParticle(const WrapperParticle&);
    void bindRender(sf::RenderTarget*);
    
    void createParticle(const WrapperParticle&);
    
    void clear();
    
    const WrapperParticle& getWrapper(const unsigned int&) const;
    const Particle& getParticle(const unsigned int&) const;
    size_t size() const;
    hz::Vector2 calcE_Force_fake(const Particle&) const;
    hz::Vector2 calcEForce(const Particle&) const;
    // void update();
    //first     -> update particle?
    //secon     -> update arrow?
    //third     -> update field?
    void update(const bool&, const bool&, std::vector<Arrow>&,
        const float&, const bool&);
    void draw(const bool&);

    /// Operators
    WrapperParticle& operator[](const size_t&);
};

#endif //!HAZEM_HANDLER_PARTICLE
