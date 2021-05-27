#include <SFML/Graphics.hpp>

class ShapeBase : public sf::Shape
{

private:

protected:
    sf::String name;
    sf::Vector2f origin;
public:
    ShapeBase(/* args */);
    explicit ShapeBase(sf::Vector2f origin);
    // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};


