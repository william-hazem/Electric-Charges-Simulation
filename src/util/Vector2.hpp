#include <cmath>

namespace hz {

    typedef float dec;

    class Vector2
    {
    
    public:
        dec x, y;

        Vector2(dec, dec);
        ~Vector2() {};

        dec abs() const;

        Vector2 operator+(Vector2&) const;
        float operator*(Vector2&) const;
        Vector2 operator*(dec a) const;
        Vector2 operator-(Vector2&) const;
        
        double angle() const;
        double angle(Vector2&) const;

        
    };
    

    


}