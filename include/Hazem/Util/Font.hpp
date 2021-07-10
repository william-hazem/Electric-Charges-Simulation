#ifndef HAZEM_FONT
#define HAZEM_FONT

#include <SFML/Graphics/Font.hpp>

namespace hz {
    
    /// \brief Load default font file
    /// \return A const font reference
    bool loadDefaultFont(sf::Font* const);

    /// \brief Load font from assets/font file
    /// \return if load suceffully return true
    bool loadFontFrom(sf::Font* const, const char*);
}



#endif //!HAZEM_FONT