#ifndef HAZEM_VECTOR2
#define HAZEM_VECTOR2

#include <cmath>

namespace hz {

    typedef double dec;

    class Vector2
    {
    
    public:
        dec x, y;

        Vector2();
        // Vector2(Vector2&);
        Vector2(const Vector2&);
        explicit Vector2(dec, dec);
        Vector2(dec, dec, dec, dec);
        ~Vector2() {};

        dec abs() const;
        Vector2 unit() const;

        Vector2 operator+(const Vector2&) const;
        float operator*(const Vector2&) const;
        Vector2 operator*(const dec a) const;
        Vector2 operator-(const Vector2&) const;
        
        void operator+=(const Vector2&);

        void setAngle(const dec);

        double angle() const;
        double angle(Vector2&) const;

        
    };
    

    


}

#endif //!HAZEM_VECTOR2