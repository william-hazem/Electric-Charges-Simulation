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
    Arrow arrow(sf::Vector2f(200, 200), 40.f, 3.5f);
    arrow.setOrign({0, 0});
    double angle = 0.01;
    // Arrow arrow2(sf::Vector2f(120, 70), 80.f, 190.f);
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Cmake");
    sf::CircleShape circle(5);
    circle.setPosition({200, 200});
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
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i mouse = sf::Mouse::getPosition();
                    printf("Mx, My = %d, %d\n", mouse.x, mouse.y);
                    printf("Mx, My = %d, %d\n", mouse.x - 600, mouse.y - 300);
                    printf("------------------\n");
                }
            }
        }

        window.clear();
       
        window.draw(arrow);
        angle += 0.1f;
        angle += 0.5f;
        
        arrow.setAngle(angle);
        // arrow.getShapesCount();
        // window.draw(arrow2);
        
        // angle += 1.1f;
        // shape.setRotation(angle);
        // window.draw(shape);
        window.draw(circle);
        // window.draw(arrow);
        // window.draw(c1);
        // if(r < 1) r += 0.005;
        // if(g < 1) g += 0.005;
        // if(b < 1) b += 0.005;
        // else {
        //     r = 0;
        //     b = 0;
        //     g = 0;
        // }
        window.setFramerateLimit(60);
        window.display();

    } 
        // window.draw(circle);
        // window.draw(circle2);
        //



    return 0;
}
