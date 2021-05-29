#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "src/graphics/Arrow2.cpp"
#include "src/graphics/ShapeCompound.hpp"

int main() {
    
    Arrow2 arrow(sf::Vector2f(20, 50), 120.f, 40.f);

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Cmake");

    arrow.setFillColor(sf::Color::Red);
    arrow.setOutlineColor(sf::Color::White);
    arrow.setOutlineThickness(1.f);
    // sf::CircleShape shape(10.f);
    // shape.setFillColor(sf::Color::Red);
    // shape.setOrigin({10.f/2, 10.f/2});
    // shape.setPosition({20.f, 50.f});

    sf::PrimitiveType* p = new sf::PrimitiveType[1];
    p[0] = sf::Quads;
    ShapeCompound shape(p, 1, nullptr, 0);
    shape.drawRectangle(60, 60, 300, 300, sf::Color::Red);

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
       
        // window.draw(arrow);
        window.draw(shape);
        
       
        window.display();

    }


    return 0;
}
