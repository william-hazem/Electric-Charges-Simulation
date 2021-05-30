#ifndef HAZEM_SHAPE_BASE
#define HAZEM_SHAPE_BASE

#include <SFML/Graphics.hpp>

static const char* const SHAPE_PREFIX = "shape_base";

class ShapeBase : public sf::Drawable
{

private:
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state);
protected:
    sf::String name = SHAPE_PREFIX;
    sf::Vector2f origin;
    sf::Vector2f position;
public:
    ShapeBase(/* args */);
    explicit ShapeBase(sf::Vector2f origin);
    // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};



#endif //!HAZEM_SHAPE_BASE