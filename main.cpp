#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "src/graphics/Arrow.hpp"
int main() {
    
    Arrow arrow(sf::Vector2f(10, 10), 50.f, 10.f);

    hz::Vector2 v(4.f, 3.f);
    printf("%f", v.abs());
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Cmake");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        // window.draw(shape);
        window.draw(arrow);
        window.display();

    }


    return 0;
}
