#include <Hazem/Graphics/Shapes/Arrow.hpp>

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

Arrow::~Arrow() {}

Arrow::Arrow(sf::Vector2f position, float length, float tickness) : ShapeCompound(primitives_parts, 3, 0, 0) {
    
    this->position = position;
    
    this->length = length;
    this->tickness = tickness;
    this->origin = {0, 0};
    this->angle = 0;
    this->drawArrow();
}

void Arrow::drawArrow() {
    // Total Lenght = L + l;
    float l = 0.3 * length;
    float L = length - l;
    // h is proporcional to lenght
    float h = tickness * l / length + 4.f;

    float x = position.x + L - origin.x;
    float y = position.y + tickness/2 - origin.y;

    this->drawRectangle(position.x - origin.x , position.y - tickness/2 - origin.y,
                        position.x + L - origin.x, position.y + tickness/2 - origin.y);
    this->swap();
    
    
    
    sf::Vector2f v[3];
    v[0] = {x, position.y - origin.y};
    v[1] = {x + l, position.y - origin.y};
    v[2] = {x, y + h};
    this->drawTriangle(v);

    v[2] = {x, position.y - tickness/2 - origin.y - h};
    this->swap();
    this->drawTriangle(v);
    this->swap();
}


void Arrow::update() {
    this->drawArrow();
}


void Arrow::fillArea() {

}
