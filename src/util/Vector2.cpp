#include <Hazem/Util/Vector2.hpp>

#include <cmath>

namespace hz {

    const double PI = 3.14159265359;

    Vector2::Vector2() {
        this->x = 0;
        this->y = 0;
    }

    Vector2::Vector2(const dec& x, const dec& y) {
        this->x = x;
        this->y = y;
    }

    Vector2::Vector2(const Vector2& v) {
        this->x = v.x;
        this->y = v.y;
    }

    Vector2::Vector2(dec x, dec y, dec sx, dec sy) {
        this->x = x / sx;
        this->y = y / sy;

    }

    dec Vector2::abs() const {
        return (dec) sqrt(
            pow(this->x, 2) + pow(this->y, 2)
        );
    }

    Vector2 Vector2::unit() const {
        double abs = this->abs();
        return Vector2 (
            this->x / abs,
            this->y / abs
        );
    }

    Vector2 Vector2::operator+(const Vector2& v) const {
        return Vector2(this->x + v.x, this->y + v.y);

    }
    
    dec Vector2::operator*(const Vector2& v) const {
        return this->x * v.x + this->y * v.y;
    }
    
    Vector2 Vector2::operator*(dec a) const {
        return Vector2(this->x * a, this->y * a);
    }

    Vector2 Vector2::operator/(const dec a) const{
        return Vector2(this->x / a, this->y / a);
    }

    Vector2 Vector2::operator-(const Vector2& v) const {
        return Vector2(this->x - v.x, this->y - v.y);
    }

    void Vector2::operator+=(const Vector2& v) {
        this->x += v.x;
        this->y += v.y;
    }


    void Vector2::setAngle(const dec angle) {
        double rad = angle * PI / 180;
        this->x = x*cos(angle) - y*sin(angle);
        this->y = y*sin(angle) + x*cos(angle);
    }


    dec Vector2::angle() const {

        // return atan2(this->x, this->y);
        return atan2(this->x, this->y) * 180 / PI;
    }

    // double Vector2::angle(Vector2& v) const {
    //     Vector2 u = *this;
    //     return acos (
    //         u * v /u.abs() /v.abs()
    //     );
    // }
}
