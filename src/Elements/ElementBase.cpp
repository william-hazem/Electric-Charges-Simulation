#include <Hazem/Elements/ElementBase.hpp>

ElementBase::ElementBase() : type(Type::Base) {}

ElementBase::ElementBase(const Type& _type) : type(_type) {}

// SETTERS
void ElementBase::setType(const ElementBase::Type& type) {
    this->type = type;
}

// GETTERS
const ElementBase::Type& ElementBase::getType() const {
    return this->type;
}