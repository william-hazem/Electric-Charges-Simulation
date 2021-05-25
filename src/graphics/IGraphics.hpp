#include <SFML/Graphics.hpp>
using namespace sf;

class Arrow : public sf::Shape
{
private:
    
public:
    Arrow(/* args */);
    void draw(RenderTarget& target, RenderStates states) const;
};


