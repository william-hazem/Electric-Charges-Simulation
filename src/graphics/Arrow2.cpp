#include <SFML/Graphics/ConvexShape.hpp>

class Arrow2 : public sf::ConvexShape
{
private:
    /* data */
public:
    Arrow2(sf::Vector2f origin, float length, float tickness) : ConvexShape(5) {
        float x = origin.x;
        float y = origin.y;
        this->setPoint(0, sf::Vector2f(x, y - tickness/2));

        this->setPoint(1, sf::Vector2f(x + length, y - tickness/2));

        this->setPoint(2, sf::Vector2f(x + length, y - tickness/2 - 30.f));

        this->setPoint(3, sf::Vector2f(x + length + 30.f, y));

        this->setPoint(4, sf::Vector2f(x , y));
    }
    ~Arrow2() {};
};

