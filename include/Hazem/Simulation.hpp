#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include <Hazem/Graphics/graphics.hpp>
#include <Hazem/Physics/Particle.hpp>
#include <Hazem/HandlerParticle.hpp>
#include <Hazem/Util/Singleton.hpp>
#include <Hazem/Elements/Elements.hpp>
// #include "Events/EventHandler.hpp"


class Simulation
{

private:
    uint64_t width, height;
    static Arrow defaultArrow;
    bool running;
    bool showForces;
    bool showEField;
    bool showAceleration;
    bool pause;
    
    sf::Font font;

    std::vector<ElementBase> elements;
    std::vector<ShapeBase*> shapes;
    std::vector<Particle> particles;
    std::vector<WrapperParticle> wp;
    HandlerParticle particleSystem;
    void init();

    void initText();
    void initElement();

    void drawTextInfo();

    /// \brief Add a new Particle
    /// \param set true for a proton
    /// and false for eletron, and set initial position
    void addParticle(bool, const hz::Vector2&);

    void updateParticles();
public:
    sf::RenderWindow window;
    Simulation();
    Simulation(uint32_t, uint32_t);
    ~Simulation();

    bool start();
    void clear();
    void run();
    friend class EventHandler;  

};

#endif //!HAZEM_SIMULATION