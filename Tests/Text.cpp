#include <iostream>
#include <SFML/Graphics.hpp>
#include <Hazem/Elements/Elements.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Testing Hz::Text");
    // window.setFramerateLimit(30);
    sf::Font font;
    if(!font.loadFromFile("../../assets/arial.ttf")) {
        printf("!ERROR!\n");
    }
    sf::Font font2;
    Hz::loadDefaultFont(&font2);
    Text t, t2;
    t.setFont(font2);
    t2.setPosition({600, 600});
    // t.setFont(font);
    t.setPosition({200, 200});
    t2.setFont(font2);
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
       
        // window.draw(text);
        window.draw(t);
        window.draw(t2);

        window.display();
    } 

    return 0;
}
