#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include "graphics/graphics.hpp"
#include "Physics/Particle.hpp"
#include "util/Singleton.hpp"

class Simulation : public hz::Singleton
{

private:
    uint64_t width, height;
    
    bool running;
    bool showForces;
    bool showEField;
    std::vector<ShapeBase*> shapes;
    std::vector<Particle> particles;
    void init();

public:
    sf::RenderWindow window;
    Simulation(uint64_t width, uint64_t height);
    ~Simulation();

    bool start();
    void clear();
    void run();

};

#endif //!HAZEM_SIMULATION