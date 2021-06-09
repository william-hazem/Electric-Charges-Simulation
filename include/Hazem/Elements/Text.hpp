#ifndef HAZEM_ELEMENT_TEXT
#define HAZEM_ELEMENT_TEXT

#include <SFML/Graphics/Text.hpp>
#include <Hazem/Util/Font.hpp>
#include <string>

#include <Hazem/Elements/ElementBase.hpp>

class Text : public sf::Text, public ElementBase {
    
public:
    Text();
    
};

#endif //!HAZEM_ELEMENT_TEXT