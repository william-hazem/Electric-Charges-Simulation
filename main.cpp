#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "graphics/Shapes/Arrow.hpp"
#include "Simulation.hpp"
int main() {
    
   
    // Arrow arrow2(sf::Vector2f(120, 70), 80.f, 190.f);
    Simulation simulation(1200, 600);
    sf::RenderWindow* window = &simulation.window;
    
    simulation.run();
    

    return 0;
}
