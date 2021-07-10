#include <Hazem/Util/Font.hpp>
#include <string>

namespace hz {

    bool loadDefaultFont(sf::Font* const font) {
        if(font == nullptr)
            return false; 
        return font->loadFromFile("assets/arial.ttf");
    }
    
    bool loadFontFrom(sf::Font* const font, const char* font_name) {
        if(font == nullptr)
            return false;
        
        return font->loadFromFile(std::string("asses/font/") + font_name);
    }
}