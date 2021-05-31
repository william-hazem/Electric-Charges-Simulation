#ifndef HAZEM_COMPOUND_SHAPE
#define HAZEM_COMPOUND_SHAPE

#include "ShapeBase.hpp"

class ShapeCompound : public sf::Drawable, public sf::Transformable {

private:
    sf::VertexBuffer* shapes;
    unsigned int n;
    unsigned int index;
    
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state) const;
    virtual void update();
protected:
    const char* name;
    sf::Color color;
    sf::Vector2f origin;
    sf::Vector2f position;
    
    /// \brief Swap the index to the next
    void swap() {

        if(++index >= n) index = 0;
    }

    void bind(std::vector<sf::Vertex>& varray, int a) {
        shapes[index].update(varray.data(), a, 0);
    }

    sf::VertexBuffer* getBuffer(uint64_t);

public:
    ShapeCompound();
    ShapeCompound(sf::PrimitiveType* primitives, int nShapes, unsigned int* offset, unsigned int nVertex);

    
    /// \brief Draw a rectangle in current buffer index
    void drawRectangle(double x1, double y1, double x2, double y2);

    /// \brief Draw a triangle in current buffer index
    /// \param vertex[3]
    void drawTriangle(sf::Vector2f* vertex);
    
    /// Getters

    unsigned int getNShapes() const;

    /// Setters

    
    void setOrign(sf::Vector2f);
    void setPosition(sf::Vector2f);

    /// \brief Absolute color rgb
    /// \param int 32 bits unsigned or a hexadecimal number 0xRRGGBB
    // void setColor(uint32_t);
    void setColor(sf::Color);

    

};


#endif //!HAZEM_COMPOUND_SHAPE