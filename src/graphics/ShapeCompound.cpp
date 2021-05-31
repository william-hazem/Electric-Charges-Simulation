#include "ShapeCompound.hpp"

ShapeCompound::ShapeCompound() {
    this->index = 0;
    this->n = 0;
    setOrign(sf::Vector2f(0, 0));
    setColor(0xFFFFFF);
}


ShapeCompound::ShapeCompound(sf::PrimitiveType* primitives, int nShapes, unsigned int* offset,
unsigned int nVertex) : ShapeCompound() {
    shapes = new sf::VertexBuffer[nShapes];
    this->n = nShapes;
    for(int i = 0; i < nShapes; i++) {
        shapes[i].setPrimitiveType(primitives[i]);
    }
}

/// GETTERS

unsigned int ShapeCompound::getNShapes() const{
    return this->n;
}

sf::VertexBuffer* ShapeCompound::getBuffer(uint64_t index) {
    if(index < this->n) 
        return nullptr;
    return &shapes[index];
}

/// SETTERS

void ShapeCompound::setColor(sf::Color color) {
    this->color = color;
}

void ShapeCompound::setColor(uint32_t color) {
    sf::Color rgb;
    rgb.r = (uint8_t) color >> 24;  //0x'RR'GGBBAA
    rgb.g = (uint8_t) color >> 16;  //0xRR'GG'BBAA
    rgb.b = (uint8_t) color >> 8;   //0xRRGG'BB'AA
    rgb.a = (uint8_t) color;        //0xRRGGBB'AA'
    this->color = rgb;

}

void ShapeCompound::setOrign(sf::Vector2f origin) {
    this->origin = origin;
}

void ShapeCompound::setPosition(sf::Vector2f position) {
    this->position = position;
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
    printf("Sucessful: %d\n", i);
        
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
    printf("Sucessfull 2: %d\n", i);

    


}