#include <Hazem/Elements/Text.hpp>

Text::Text() : ElementBase(ElementBase::Type::Text) {
    this->setCharacterSize(24);
    this->setFillColor(sf::Color::White);
    this->setPosition(500, 500);
    this->setString(std::string("Text"));
}