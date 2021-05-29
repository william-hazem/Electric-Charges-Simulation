#include "Arrow.hpp"

Arrow::Arrow() : ShapeBase() {
   this->name = "shapeArrow";
    this->length = 1.f;
    this->tickness = .1f;
}

Arrow::Arrow(sf::Vector2f origin, float lenght, float tickness) : ShapeBase(origin) {
    this->name = "shapeArrow";
    this->length = lenght;
    this->tickness = tickness;

}


unsigned int Arrow::getPointCount() const {
    return 5;
}
sf::Vector2f Arrow::getPoint(unsigned int index) const {
    float x = origin.x;
    float y = origin.y;

    if(index == 0) 
        return {x, y - tickness/2};
    if(index == 1)
        return {x + length, y - tickness/2};
    if(index == 2)
        return {x + length, y - tickness/2 - 30.f};
    if(index == 3)
        return {x + length + 30.f, y};
    return {x , y};
    
    
}


void Arrow::fillArea() {
    int i = this->getPointCount();
    for(; i > 0; i--)
    {
        
    }

    


}