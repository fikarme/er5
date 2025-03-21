#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const string &name, const string &effects) : name(name), effects(effects) {}

ASpell::ASpell(const ASpell &other) : name(other.name), effects(other.effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &other) {
    name = other.name;
    effects = other.effects;
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

