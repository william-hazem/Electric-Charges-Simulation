#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/util/Vector2.hpp"
#include "graphics/Shapes/Arrow.hpp"
#include "Simulation.hpp"
#include <OpenGL.hpp>

int main() {
    sf::CircleShape c(25.f);
    c.setPosition({0, 0});
    c.setOrigin({25, 25});
    sf::CircleShape c1 = c;
    c1.setOrigin({25.f, 25.f});
    c1.setPosition({150, 150});
    c1.setFillColor(sf::Color::Red);
    sf::RectangleShape shape({50, 50});
    shape.setPosition({150, 150});
    shape.setOrigin({100, 100});
    double angle = 0.05f;
    sf::RenderWindow window({1400, 1100}, "TEST SCREEN");
    // Arrow arrow2(sf::Vector2f(120, 70), 80.f, 190.f);
    // Simulation simulation(1200, 600);
    // sf::RenderWindow* window = &simulation.window;
    // float thetaSpeed = 0.05;
    // simulation.run();
    // float r, g, b;
    // r = 0;
    // g = 0;
    // b = 0;
    sf::View view = window.getView();
    view.move({-700, -550});
    view.zoom(1.9);
    window.setView(view);
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // glBegin(GL_QUADS);
        // glClear(GL_COLOR_BUFFER_BIT);
        // float vertices[] = 
        // {
        //     -0.5, 0.5, 0,
        //     0.5, 0.5, 0.0,
        //     0.5, -0.5, 0.0,
        //     -0.5, -0.5, 0.0
        // };
        // glColor3d(r, g, b);
        // glVertex3f(-0.5, 0.5, 0);
        // glColor3d(0, g, 0);
        // glVertex3f(0.5, 0.5, 0.0);
        // glColor3d(r, g, b);
        // glVertex3f(0.5, -0.5, 0.0);
        // glColor3d(r, g, b);
        // glVertex3f(-0.5, -0.2, 0.0);
        // glEnd();
        // glRotatef(thetaSpeed, 1, 0.5, 1);
        
        angle += 1.1f;
        shape.setRotation(angle);
        window.draw(shape);
        window.draw(c);
        window.draw(c1);
        // if(r < 1) r += 0.005;
        // if(g < 1) g += 0.005;
        // if(b < 1) b += 0.005;
        // else {
        //     r = 0;
        //     b = 0;
        //     g = 0;
        // }
        window.setFramerateLimit(30);
        window.display();

    }



    return 0;
}
