#include "ShapeCompound.hpp"

ShapeCompound::ShapeCompound() {
    this->index = 0;
    this->s_size = 0;
    setOrign(sf::Vector2f(0, 0));
    setColor(sf::Color::White);
}


ShapeCompound::ShapeCompound(sf::PrimitiveType* primitives, int nShapes, unsigned int* offset,
unsigned int nVertex) {
    this->index = 0;
    shapes = new sf::VertexBuffer[nShapes];
    setColor(sf::Color::White);
    this->s_size = nShapes;
    for(int i = 0; i < nShapes; i++) {
        shapes[i].setPrimitiveType(primitives[i]);
    }
}

void ShapeCompound::draw(sf::RenderTarget& render, sf::RenderStates state) const {
    sf::Transform transformation;
    // static int tetha = 1;
    angle += 0.05f;
    transformation.rotate(angle);
    // transformation.translate(100, 100);
    state.transform = transformation;
    for(int i = 0; i < s_size; i++) {
        render.draw(shapes[i], state);
    }
}

void ShapeCompound::update() {
    /// \todo
}

/// GETTERS

unsigned int ShapeCompound::getNShapes() const{
    return this->s_size;
}

sf::VertexBuffer* ShapeCompound::getBuffer(uint64_t index) {
    if(index < this->s_size) 
        return nullptr;
    return &shapes[index];
}



/// Particular

void ShapeCompound::drawRectangle(double x1, double y1, double x2, double y2) {
    double temp;
    if (x1 > x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    std::vector<sf::Vertex> varray(4);
    shapes[index].create(4);
    varray[0].position = sf::Vector2f(x1, y1);
    varray[1].position = sf::Vector2f(x2, y1);
    varray[2].position = sf::Vector2f(x2, y2);
    varray[3].position = sf::Vector2f(x1, y2);
    
    varray[0].color = color;
    varray[1].color = color;
    varray[2].color = color;
    varray[3].color = color;
    bool i = shapes[index].update(varray.data(), 4, 0);
        
}

void ShapeCompound::drawTriangle(sf::Vector2f* vertex) {     
   sf::Vertex v[3];
    v[0].position = vertex[0];
    v[0].color = this->color;
    v[1].position = vertex[1];
    v[1].color = this->color;
    v[2].position = vertex[2];
    v[2].color = this->color;

    
    shapes[index].create(3);
    bool i = shapes[index].update(v, 3, 0);

    


}

void ShapeCompound::drawRect(double x1, double y1, double x2, double y2) {
    double temp;
    if (x1 > x2) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (y1 > y2) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    if(!shapes[this->index].getVertexCount())
        shapes[this->index].create(4);

    double vertex[4];
    vertex[0] = {};
}