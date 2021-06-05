#ifndef HAZEM_COMPOUND_SHAPE
#define HAZEM_COMPOUND_SHAPE

#include "ShapeBase.hpp"

class ShapeCompound : public ShapeBase {

private:
    sf::VertexBuffer* shapes;
    unsigned int s_size;
    unsigned int index;
    mutable double angle = 0.1;
    virtual void draw(sf::RenderTarget& render, sf::RenderStates state) const;
    virtual void update();
protected:
    

    
    /// \brief Swap the index to the next
    void swap() {

        if(++index >= s_size) index = 0;
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


    void drawRect(double x1, double y1, double x2, double y2);
    
    /// \brief Draw a triangle in current buffer index
    /// \param vertex[3]
    void drawTriangle(sf::Vector2f* vertex);
    
    /// Getters

    unsigned int getNShapes() const;

    /// Setters

    
    

    

};


#endif //!HAZEM_COMPOUND_SHAPE