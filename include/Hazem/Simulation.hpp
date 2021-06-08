#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include "graphics/graphics.hpp"
#include "Physics/Particle.hpp"
#include "WrapperParticle.hpp"
#include "util/Singleton.hpp"
// #include "Events/EventHandler.hpp"


class Simulation
{

private:
    uint64_t width, height;
    
    bool running;
    bool showForces;
    bool showEField;
    bool showAceleration;
    
    std::vector<ShapeBase*> shapes;
    std::vector<Particle> particles;
    void init();

    void initText();

public:
    sf::RenderWindow window;
    Simulation();
    Simulation(uint64_t width, uint64_t height);
    ~Simulation();

    bool start();
    void clear();
    void run();
    friend class EventHandler;  

};

#endif //!HAZEM_SIMULATION