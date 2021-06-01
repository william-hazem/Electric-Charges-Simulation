#ifndef HAZEM_SHAPE_BASE
#define HAZEM_SHAPE_BASE

#include <SFML/Graphics.hpp>

static const char* const SHAPE_PREFIX = "shape_base";

class ShapeBase : public sf::Drawable, public sf::Transformable
{

private:
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state);
    virtual void update() = 0;

protected:
    const char* name = SHAPE_PREFIX;
    sf::Vector2f origin;
    sf::Vector2f position;
    sf::Color color;
public:
    ShapeBase(/* args */);
    explicit ShapeBase(sf::Vector2f position);
    // virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;


    void setOrign(sf::Vector2f);
    void setPosition(sf::Vector2f);

    /// \brief Absolute color rgb
    /// \param int 32 bits unsigned or a hexadecimal number 0xRRGGBB
    // void setColor(uint32_t);
    void setColor(sf::Color);
};



#endif //!HAZEM_SHAPE_BASE