#ifndef HAZEM_ARROWSHAPE
#define HAZEM_ARROWSHAPE

#include "ShapeCompound.hpp"

sf::PrimitiveType HZ_ARROW[] = {
    sf::Quads,
    sf::Triangles
};

class Arrow2 : public ShapeCompound
{
private:
    
public:
    Arrow2() : ShapeCompound(){}
    Arrow2(sf::Vector2f position, float length, float tickness) : ShapeCompound(HZ_ARROW, 1, 0, 0) {
        
        this->position = position;
        this->color = sf::Color::Green;
        this->drawRectangle(position.x, position.y, length, tickness, color);

    }
    ~Arrow2() {};
};

#endif //HAZEM_ARROWSHAPE