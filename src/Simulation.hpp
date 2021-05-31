#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include "graphics/graphics.hpp"
#include "util/Singleton.hpp"

class Simulation : public hz::Singleton
{

private:
    bool running        = false;
    bool showForces     = false;
    bool showEField     = false;
    std::vector<ShapeBase> shapes;
    

public:
    Simulation(/* args */);
    ~Simulation();

};

#endif //!HAZEM_SIMULATION