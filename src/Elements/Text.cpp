#include <Hazem/Elements/Text.hpp>

Text::Text() {
    sf::Font font;
    if(font.loadFromFile("assets/CaviarDreams.ttf"))
    {
        
        printf("LOADED!\n");
    }
    this->text = sf::Text();
    this->text.setFont(font);
    this->text.setCharacterSize(24);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(500, 500);
    this->text.setString(std::string("Text"));

}
