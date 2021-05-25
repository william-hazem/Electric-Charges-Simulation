#include "Vector2.hpp"
#include <cmath>

namespace hz {

    Vector2::Vector2(dec x, dec y) {
        this->x = x;
        this->y = y;
    }

    dec Vector2::abs() const {
        return sqrt(
            pow(x, 2) + pow(y, 2)
        );
    }

    Vector2 Vector2::operator+(Vector2& v) const {
        return Vector2(this->x + v.x, this->y + v.y);

    }
    
    float Vector2::operator*(Vector2& v) const {
        return this->x * v.x + this->y * v.y;
    }
    
    Vector2 Vector2::operator*(dec a) const {
        return Vector2(this->x * a, this->y * a);
    }

    Vector2 Vector2::operator-(Vector2& v) const {
        return Vector2(this->x - v.x, this->y - v.y);
    }
}
