#include <cmath>

namespace hz {

    typedef float dec;

    class Vector2
    {
    
    public:
        dec x, y;

        Vector2(dec, dec);

        dec abs() const;

        Vector2 operator+(Vector2&) const;
        float operator*(Vector2&) const;
        Vector2 operator*(dec a) const;
        Vector2 operator-(Vector2&) const;
        


        ~Vector2() {};
    };
    

    


}