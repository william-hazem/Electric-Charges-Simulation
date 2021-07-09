// #define WIN_32
#include <iostream>
#include <Hazem/Simulation.hpp>

int main() {
    try {
        // Simulation simulation(1200, 900);
        Simulation* simulation = Simulation::getInstance();
        simulation->run();
    }
    catch(std::exception e) {
        std::cout << e.what() << std::endl;
            
    }    
    return 0;
}
