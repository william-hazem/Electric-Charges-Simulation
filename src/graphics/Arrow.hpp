#ifndef HAZEM_ARROWSHAPE
#define HAZEM_ARROWSHAPE
#include "ShapeCompound.hpp"



class Arrow : public ShapeCompound {
protected:
    float length;
    float tickness;

public:
    Arrow();
    Arrow(sf::Vector2f position, float length, float tickness);
    void fillArea();
    


    void update();
};

#endif //HAZEM_ARROWSHAPE