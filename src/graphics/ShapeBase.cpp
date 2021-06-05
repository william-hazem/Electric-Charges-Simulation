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

/*
 *   SETTERS
**/

void ShapeBase::setColor(sf::Color color) {
    this->color = color;
    this->update();
}

// void ShapeCompound::setColor(uint32_t color) {
//     sf::Color rgb;
//     rgb.r = (uint8_t) color >> 24;  //0x'RR'GGBBAA
//     rgb.g = (uint8_t) color >> 16;  //0xRR'GG'BBAA
//     rgb.b = (uint8_t) color >> 8;   //0xRRGG'BB'AA
//     rgb.a = (uint8_t) color;        //0xRRGGBB'AA'
//     this->color = rgb;

// }

void ShapeBase::setOrign(sf::Vector2f origin) {
    this->origin = origin;
    this->update();
}

void ShapeBase::setPosition(sf::Vector2f position) {
    this->position = position;
    this->update();
}

void ShapeBase::setAngle(double angle) {
    this->angle = angle;
}