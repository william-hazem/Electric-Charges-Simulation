#ifndef HAZEM_SHAPE_ARROW
#define HAZEM_SHAPE_ARROW

#include "../ShapeCompound.hpp"

class Arrow : public ShapeCompound {

private:
    void drawArrow();
    virtual void update();
protected:
    float length;
    float tickness;

public:
    Arrow();
    Arrow(sf::Vector2f position, float length, float tickness);
    void fillArea();
    
};

#endif //HAZEM_SHAPE_ARROW