#include "ShapeCompound.hpp"

ShapeCompound::ShapeCompound() {
    setOrign(sf::Vector2f(0, 0));
    setColor(0xFFFFFF);
}


ShapeCompound::ShapeCompound(sf::PrimitiveType* primitives, int nShapes, unsigned int* offset, unsigned int nVertex) {
    index = 0;
    shapes = new sf::VertexBuffer[nShapes];
    this->n = nShapes;
    for(int i = 0; i < nShapes; i++) {
        shapes[i].setPrimitiveType(primitives[i]);
    }
}


/// SETTERS

void ShapeCompound::setColor(sf::Color color) {
    this->color = color;
}

void ShapeCompound::setColor(uint32_t color) {
    sf::Color rgb;
    rgb.r = (uint8_t) color >> 24;  //0x'RR'GGBBAA
    rgb.g = (uint8_t) color >> 16;  //0xRR'GG'BBAA
    rgb.b = (uint8_t) color >> 8;   //0xRRGG'BB'AA
    rgb.a = (uint8_t) color;        //0xRRGGBB'AA'
    this->color = rgb;

}

void ShapeCompound::setOrign(sf::Vector2f orign) {
    this->orign = orign;
}

void ShapeCompound::setPosition(sf::Vector2f position) {
    this->position = position;
}