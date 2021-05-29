#include <SFML/Graphics.hpp>

class ShapeBase : public sf::Drawable
{

private:
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state);
protected:
    sf::String name;
    sf::Vector2f origin;
public:
    ShapeBase(/* args */);
    explicit ShapeBase(sf::Vector2f origin);
    // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};


