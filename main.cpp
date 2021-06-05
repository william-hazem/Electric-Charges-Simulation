#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "graphics/Shapes/Arrow.hpp"
int main() {
    
    Arrow arrow(sf::Vector2f(0, 0), 40.f, 3.5f);
    arrow.setOrign({0, 0});
    double angle = 0.01;
    // Arrow arrow2(sf::Vector2f(120, 70), 80.f, 190.f);
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Cmake");

    // sf::PrimitiveType* p = new sf::PrimitiveType[1];
    // p[0] = sf::Quads;
    // ShapeCompound shape(p, 1, nullptr, 0);
    // shape.drawRectangle(60, 60, 300, 300);

    sf::CircleShape circle(5);
    circle.setPosition({0, 0});
    circle.setOrigin({5, 5});
    circle.setFillColor(sf::Color::Green);
    sf::CircleShape circle2(5);
    circle2.setPosition({40, 50});
    circle2.setOrigin({5, 5});
    circle2.setFillColor(sf::Color::Red);
    // circle2.setOrigin({35, 35});
    sf::View view;
    view.move({-600, -400});
    
    window.setView(view);
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
        // window.draw(circle);
        // window.draw(circle2);
        // angle += 0.1f;
        angle = 45;
        
        arrow.setAngle(0);
        // window.draw(arrow2);
        
        window.display();

    }


    return 0;
}
