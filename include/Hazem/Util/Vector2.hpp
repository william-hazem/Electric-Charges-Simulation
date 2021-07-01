#ifndef HAZEM_VECTOR2
#define HAZEM_VECTOR2



namespace hz {
    typedef float dec;

    class Vector2
    {
    
    public:
        dec x, y;

        Vector2();
        // Vector2(Vector2&);
        Vector2(const Vector2&);
        explicit Vector2(const dec&, const dec&);
        Vector2(dec, dec, dec, dec);
        ~Vector2() {};

        dec abs() const;
        Vector2 unit() const;

        Vector2 operator+(const Vector2&) const;
        dec operator*(const Vector2&) const;
        Vector2 operator-(const Vector2&) const;
        
        Vector2 operator*(const dec a) const;
        Vector2 operator/(const dec a) const;

        void operator+=(const Vector2&);
        void operator-=(const Vector2&);
        
        void setAngle(const dec);
        dec angle() const;

        
    };
    

    


}

#endif //!HAZEM_VECTOR2