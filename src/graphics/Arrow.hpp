#ifndef HAZEM_ARROWSHAPE
#define HAZEM_ARROWSHAPE
#include "ShapeCompound.hpp"



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

#endif //HAZEM_ARROWSHAPE