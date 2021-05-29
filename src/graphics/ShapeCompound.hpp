#include "ShapeBase.hpp"

class ShapeCompound : public sf::Drawable {

private:
    sf::VertexBuffer* shapes;
    unsigned int n;

    virtual void draw(sf::RenderTarget& render, sf::RenderStates state) const {
        
        // for(int i = 0; i < n; i++)
            render.draw(shapes[0]);
    }


public:
    ShapeCompound() {};

    ShapeCompound(sf::PrimitiveType* primitives, int nShapes, unsigned int* offset, unsigned int nVertex) {
        shapes = new sf::VertexBuffer[nShapes];
        this->n = nShapes;
        for(int i = 0; i < nShapes; i++) {
            shapes[i].setPrimitiveType(primitives[i]);
        }
    }

    

    void drawRectangle(double x1, double y1, double x2, double y2, sf::Color color) {
        double temp;
        if (x1 > x2) {
            temp = x2;
            x1 = x2;
            x2 = temp;
        }
        if (y1 > y2) {
            temp = y2;
            y1 = y2;
            y2 = temp;
        }

        std::vector<sf::Vertex> varray(4);
        shapes[0].create(4);
        varray[0].position = sf::Vector2f(x1, y1);
        varray[1].position = sf::Vector2f(x2, y1);
        varray[2].position = sf::Vector2f(x2, y2);
        varray[3].position = sf::Vector2f(x1, y2);
        
        varray[0].color = color;
        varray[1].color = color;
        varray[2].color = color;
        varray[3].color = color;
        bool i = shapes[0].update(varray.data(), 4, 0);
        printf("Sucessful: %d\n", i);
        
    }


};