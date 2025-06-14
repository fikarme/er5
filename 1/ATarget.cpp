#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const string &type) : type(type) {}

ATarget::ATarget(const ATarget &cpy) : type(cpy.type) {}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &rhs) {
    type = rhs.type;
    return *this;
}

const string &ATarget::getType() const {
    return type;
}

void ATarget::getHitBySpell(const ASpell &spell) const {
    cout << type << " has been " << spell.getEffects() << "!" << endl;
}
