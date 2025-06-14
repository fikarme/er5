#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const string &name, const string &effects) : name(name), effects(effects) {}

ASpell::ASpell(const ASpell &cpy) : name(cpy.name), effects(cpy.effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &rhs) {
    name = rhs.name;
    effects = rhs.effects;
    return *this;
}

const string &ASpell::getName() const {
    return name;
}

const string &ASpell::getEffects() const {
    return effects;
}

void ASpell::launch(const ATarget &target) const {
    target.getHitBySpell(*this);
}
