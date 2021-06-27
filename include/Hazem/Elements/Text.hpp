#ifndef HAZEM_ELEMENT_TEXT
#define HAZEM_ELEMENT_TEXT

#include <SFML/Graphics/Text.hpp>
#include <Hazem/Util/Font.hpp>
#include <string>

#include <Hazem/Elements/ElementBase.hpp>

class Text : public sf::Text, public ElementBase {
    void init();
public:
    Text();
    Text(const char*);
    Text(const char*, const char*, const sf::Vector2f& = sf::Vector2f(0,0));
    void setOpacity(const int);
    int getOpacity() const;
};

#endif //!HAZEM_ELEMENT_TEXT