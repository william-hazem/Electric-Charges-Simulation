#include <Hazem/Util/Font.hpp>

namespace Hz {

    bool loadDefaultFont(sf::Font* const font) {
        if(font == nullptr)
            return false; 
        return font->loadFromFile("assets/arial.ttf");
    }
    
}