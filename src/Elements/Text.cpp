#include <Hazem/Elements/Text.hpp>

Text::Text() : ElementBase(ElementBase::Type::Text) {
    init();
}

Text::Text(const char* name) : ElementBase(ElementBase::Type::Text) {
    init();
    setElement_Name(name);
}

Text::Text(const char* name, const char* string, const sf::Vector2f& position) {
    init();
    setElement_Name(name);
    setString(string);
    setPosition(position);
}


void Text::init() {
    this->setCharacterSize(24);
    this->setFillColor(sf::Color::White);
    this->setPosition(500, 500);
    this->setString(std::string("Text"));
}

void Text::setOpacity(const int opacity) {
    sf::Color color = getFillColor();
    color.a = opacity;
    setFillColor(color);
}

int Text::getOpacity() const {
    return getFillColor().a;
}