#ifndef HAZEM_ELEMENT_BASE
#define HAZEM_ELEMENT_BASE

class ElementBase
{
public:

    enum Type {
        Base = 0,
        Text = 1,
    };

    ElementBase();
    ElementBase(const Type&);

    // SETTERS
    void setType(const Type&);
    // GETTERS
    const Type& getType() const;

private:
    Type type;
};


#endif //!HAZEM_ELEMENT_BASE