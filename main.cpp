#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "graphics/Arrow.hpp"
int main() {
    
    Arrow arrow(sf::Vector2f(60, 60), 40.f, 1.5f);
    arrow.setOrign({20, 10});
    // Arrow arrow2(sf::Vector2f(120, 70), 80.f, 190.f);
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Cmake");

    // sf::PrimitiveType* p = new sf::PrimitiveType[1];
    // p[0] = sf::Quads;
    // ShapeCompound shape(p, 1, nullptr, 0);
    // shape.drawRectangle(60, 60, 300, 300);

    sf::CircleShape circle(5);
    circle.setPosition({60, 60});
    circle.setOrigin({5, 5});
    circle.setFillColor(sf::Color::Green);
    sf::CircleShape circle2(5);
    circle2.setPosition({40, 50});
    circle2.setOrigin({5, 5});
    circle2.setFillColor(sf::Color::Red);
    // circle2.setOrigin({35, 35});
    
    
    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
       
        window.draw(arrow);
        // window.draw(arrow);
        window.draw(circle);
        window.draw(circle2);
        // window.draw(arrow2);
        
        window.display();

    }


    return 0;
}
