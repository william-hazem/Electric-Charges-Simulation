#include "ShapeBase.hpp"

ShapeBase::ShapeBase() {
    this->name = "";
    this->origin = sf::Vector2f(0.f ,0.f);
    //this->setFillColor (sf::Color::White);

}

ShapeBase::ShapeBase(sf::Vector2f origin) {
    this->name = "";
    this->origin = origin;
    //this->setFillColor (sf::Color::White);
}

/// PRIVATE MEMBERS
void ShapeBase::draw(sf::RenderTarget& render, sf::RenderStates state) {
    //Implement
}