#include "Arrow.hpp"

sf::PrimitiveType primitives_parts[3] = {
    sf::Quads,
    sf::Triangles,
    sf::Triangles
};

Arrow::Arrow() : ShapeCompound() {
    this->name = "shapeArrow";
    this->length = 1.f;
    this->tickness = .1f;
}

Arrow::Arrow(sf::Vector2f position, float length, float tickness) : ShapeCompound(primitives_parts, 3, 0, 0) {
    
    this->position = position;
    
    this->drawRectangle(position.x, position.y, length, tickness);
    this->swap();
    
    sf::Vector2f v[3];
    v[0] = {100, 100};
    v[1] = {100, 200};
    v[2] = {200, 100};
    this->drawTriangle(v);
    this->color = sf::Color::Red;
    v[1] = {100, 0};
    this->swap();
    this->drawTriangle(v);
    

}

void Arrow::fillArea() {


}

void Arrow::update() {
    int i;
    for(i = 0; i < this->getNShapes(); i++) {

    }
}