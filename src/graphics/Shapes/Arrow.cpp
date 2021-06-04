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
    this->angle = 0;
}

Arrow::Arrow(sf::Vector2f position, float length, float tickness) : ShapeCompound(primitives_parts, 3, 0, 0) {
    
    this->position = position;
    
    this->length = length;
    this->tickness = tickness;
    this->origin = {0, 0};
    this->angle = 0;
    this->drawArrow();
    // this->drawRectangle(position.x, position.y, length, tickness);
    // this->swap();
    
    // sf::Vector2f v[3];
    // v[0] = {100, 100};
    // v[1] = {100, 200};
    // v[2] = {200, 100};
    // this->drawTriangle(v);
    // this->color = sf::Color::Red;
    // v[1] = {100, 0};
    // this->swap();
    // this->drawTriangle(v);
    

}

void Arrow::drawArrow() {
    // Total Lenght = L + l;
    float l = 0.3 * length;
    float L = length - l;
    // h is proporcional to lenght
    float h = tickness * l / length + 4.f;

    float x = position.x + L - origin.x;
    float y = position.y + tickness/2 - origin.y;

    hz::Vector2 p1, p2;
    double xf = 0;
    double yf = 0;
    // p1 = hz::Vector2(position.x + xf - origin.x, position.y + yf - origin.y);
    p1 = hz::Vector2(position.x, position.y);
    // p2 = hz::Vector2(position.x + xf + L - origin.x, position.y + yf + tickness - origin.y);
    p2 = hz::Vector2(position.x + L, position.y + tickness);
    p1.x += origin.x;
    p2.x += origin.x;
    p1.y += origin.y;
    p2.y += origin.y;
    this->setRotation(90);
    printf("P1 = (%.*f, %.*f)\n", p1.x, p1.y);

    
    this->drawRectangle(p1.x , p1.y, p2.x, p2.y);
    this->swap();
    
   
    
    sf::Vector2f v[3];
    v[0] = {x, y};
    v[1] = {x + l, y};
    v[2] = {x, y + h};
    this->drawTriangle(v);
    // this->color = sf::Color::Red;
    v[2] = {x, y - h};
    this->swap();
    this->drawTriangle(v);
    this->swap();
}


void Arrow::update() {
    this->drawArrow();
}


void Arrow::fillArea() {


}

void Arrow::setAngle(const double angle) {
    this->angle = angle;
}

double Arrow::getAngle() const {
    return this->angle;
}