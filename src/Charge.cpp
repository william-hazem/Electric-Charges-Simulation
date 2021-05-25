#include "Charge.hpp"


float Charge::getDistance(sf::Vector2f& position) const {

    sf::Vector2f deltaR = this->position - position;
    float distance = sqrt(pow(position.x, 2) + pow(position.y, 2));
    return distance;
}

float Charge::getForceIn(Charge& q) const {


}

float Charge::getK() {
    return 1/4/PI/E0;
}


Charge::Charge(/* args */)
{
}

Charge::~Charge()
{
}
