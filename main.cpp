#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "graphics/Arrow.hpp"
int main() {
    
    Arrow arrow(sf::Vector2f(20, 50), 120.f, 40.f);
    // Arrow arrow2(sf::Vector2f(120, 70), 80.f, 190.f);
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Cmake");

    sf::PrimitiveType* p = new sf::PrimitiveType[1];
    p[0] = sf::Quads;
    ShapeCompound shape(p, 1, nullptr, 0);
    shape.drawRectangle(60, 60, 300, 300);

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       
        // window.draw(arrow);
        window.draw(arrow);
        // window.draw(arrow2);
        
        window.display();

    }


    return 0;
}
