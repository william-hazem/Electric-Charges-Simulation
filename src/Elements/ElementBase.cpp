#include <Hazem/Elements/ElementBase.hpp>

ElementBase::ElementBase() : type(Type::Base) {}

ElementBase::ElementBase(const Type& _type) : type(_type) {}

ElementBase::ElementBase(const Type& _type, const char* _name) : type(_type), 
    name(_name) {}

// SETTERS
void ElementBase::setType(const ElementBase::Type& type) {
    this->type = type;
}

void ElementBase::setElement_Name(const char* name) {
    this->name = name;
}

// GETTERS
const ElementBase::Type& ElementBase::getType() const {
    return this->type;
}

const char* ElementBase::getElement_Name() const {
    return name;
}