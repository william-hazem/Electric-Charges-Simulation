#include <iostream>
#define WIN_32

#include <SFML/Graphics.hpp>
#include <Hazem/Graphics/graphics.hpp>
#include <Hazem/Simulation.hpp>
#include <OpenGL.hpp>

int main() {
    
    Simulation simulation(1200, 900);
    simulation.run();

    return 0;
}
