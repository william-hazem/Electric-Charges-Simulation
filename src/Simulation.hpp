#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include "graphics/graphics.hpp"
#include "util/Singleton.hpp"

class Simulation : public hz::Singleton
{

private:
    bool running;
    bool showForces;
    bool showEField;
    std::vector<ShapeBase*> shapes;
    
    void init();
protected:

   

public:
    Simulation(/* args */);
    ~Simulation();

    bool start();


};

#endif //!HAZEM_SIMULATION