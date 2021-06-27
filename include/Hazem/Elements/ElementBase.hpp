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
    ElementBase(const Type&, const char*);
    ~ElementBase() {}
    // SETTERS
    void setType(const Type&);
    // GETTERS
    const Type& getType() const;
    void setElement_Name(const char*);
    const char* getElement_Name() const;
private:
    Type type;
    const char* name;
};


#endif //!HAZEM_ELEMENT_BASE