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
    this->update();

}


unsigned int Arrow::getPointCount() const {
    return 7;
}
sf::Vector2f Arrow::getPoint(unsigned int index) const {
    printf("called index %d: \n", index);
    if(index == 0) {

        return sf::Vector2f(this->origin.x, this->origin.y + tickness/2);

    }else
    if(index == 1) {
        return sf::Vector2f(this->origin.x + length, this->origin.y + tickness/2);
    }else
    if(index == 2) {
        return sf::Vector2f(this->origin.x + length, this->origin.y + tickness/2 + 10.5f);
    }else
    if(index == 3) {
        return sf::Vector2f(this->origin.x + length + 10.f, this->origin.y);
    }else
    if(index == 4) {
        return sf::Vector2f(this->origin.x + length, this->origin.y - tickness/2 - 10.5f);
    }else
    if(index == 5) {
        return sf::Vector2f(this->origin.x + length, this->origin.y - tickness/2);
    }else
    if(index == 6) {
        return sf::Vector2f(this->origin.x, this->origin.y - tickness/2);
    }
    return {0,0};
}