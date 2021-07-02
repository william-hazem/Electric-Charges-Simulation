#ifndef HAZEM_SHAPE_BASE
#define HAZEM_SHAPE_BASE

#include <SFML/Graphics.hpp>

static const char* const SHAPE_PREFIX = "shape_base";

class ShapeBase : public sf::Drawable, public sf::Transformable
{
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state);
    virtual void update() = 0;

protected:
    const char* name = SHAPE_PREFIX;
    sf::Vector2f origin;
    sf::Vector2f position;
    sf::Color color;
    double angle;
public:
    ShapeBase();
    explicit ShapeBase(const sf::Vector2f& position);
    ~ShapeBase() {};
    void setOrign(const sf::Vector2f&);
    void setPosition(const sf::Vector2f&);
    void setAngle(const double&);
    /// \brief Absolute color rgb
    /// \param int 32 bits unsigned or a hexadecimal number 0xRRGGBB
    // void setColor(uint32_t);
    void setColor(const sf::Color&);

    // GETTERS
    const sf::Vector2f& getPosition() const;
};



#endif //!HAZEM_SHAPE_BASE