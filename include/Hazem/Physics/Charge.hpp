#include <SFML/System.hpp>
#include <cmath>

const float PI = 3.14159265359;
const float E0 = 8.85e-12;

class Charge
{
private:
    float intensity;
    sf::Vector2f position;
public:
    Charge(/* args */);
    ~Charge();

    float getDistance(sf::Vector2f&) const;

    float getForceIn(Charge& q) const;
     
    static float getK();
};

Charge::Charge(/* args */)
{
}

Charge::~Charge()
{
}
