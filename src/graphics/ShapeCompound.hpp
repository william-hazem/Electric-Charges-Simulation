#ifndef HAZEM_COMPOUND_SHAPE
#define HAZEM_COMPOUND_SHAPE

#include "ShapeBase.hpp"

class ShapeCompound : public sf::Drawable {

private:
    sf::VertexBuffer* shapes;
    unsigned int n;
    unsigned int index;
    
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state) const {
        for(int i = 0; i < n; i++) {
            render.draw(shapes[i], state);
        }
    }

protected:
    const char* name;
    sf::Color color;
    sf::Vector2f origin;
    sf::Vector2f position;
    
    void swap() {

        if(++index >= n) index = 0;
        printf("current index: %d\n", index);
    }

    void bind(std::vector<sf::Vertex>& varray, int a) {
        shapes[index].update(varray.data(), a, 0);
    }

    sf::VertexBuffer* getBuffer(uint64_t);

public:
    ShapeCompound();

    ShapeCompound(sf::PrimitiveType* primitives, int nShapes, unsigned int* offset, unsigned int nVertex);

    

    void drawRectangle(double x1, double y1, double x2, double y2);
    /// \brief Draw a triangle
    /// \param vertex[3]
    void drawTriangle(sf::Vector2f* vertex);
    
    /// Getters

    unsigned int getNShapes() const;

    /// Setters
    void setColor(sf::Color);

    /// \brief Absolute color rgb
    /// \param int 32 bits unsigned or a hexadecimal number 0xRRGGBB
    void setColor(uint32_t);
    void setOrign(sf::Vector2f);
    void setPosition(sf::Vector2f);
    

};


#endif //!HAZEM_COMPOUND_SHAPE