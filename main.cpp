#include <iostream>
#define WIN_32

#include <SFML/Graphics.hpp>
#include <Hazem/Graphics/graphics.hpp>
#include <Hazem/Simulation.hpp>
#include <OpenGL.hpp>

int main() {
    try
    {
        Simulation simulation(1200, 900);
        simulation.run();
    }
    catch(std::exception e) {
        printf("[ERROR] %s\n", e.what());
        printf("[ERROR] %d\n", __LINE__);
            
    }
    
    

    
    return 0;
}
