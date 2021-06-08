#include <iostream>
#include <SFML/Graphics.hpp>
#include <Hazem/Elements/Elements.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Hz::Text");
    // window.setFramerateLimit(30);
    // Text text;
    sf::Font font;
    if(font.loadFromFile("assets/CaviarDreams.ttf"))
    {
        printf("LOADED!\n");
    }
    sf::Text text = sf::Text();
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(500, 500);
    text.setString(std::string("Text"));
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            // if(event.type == sf::Event::MouseButtonPressed) {
            //     if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //         sf::Vector2i mouse = sf::Mouse::getPosition();
            //         printf("Mx, My = %d, %d\n", mouse.x, mouse.y);
            //         printf("Mx, My = %d, %d\n", mouse.x - 600, mouse.y - 300);
            //         printf("------------------\n");
            //     }
            // }
        }

        window.clear();
       
        window.draw(text);

        window.display();
    } 

    return 0;
}
