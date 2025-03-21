#include "Warlock.hpp"

Warlock::Warlock(const string &name, const string &title) : name(name), title(title) {
    cout << name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock() {
    cout << name << ": My job here is done!" << endl;
}

const string &Warlock::getName() const {
    return name;
}

const string &Warlock::getTitle() const {
    return title;
}

void Warlock::setTitle(const string &newTitle) {
    title = newTitle;
}

void Warlock::introduce() const {
    cout << name << ": I am " << name << ", " << title << "!" << endl;
}

void Warlock::learnSpell(ASpell *spell) {
    for (size_t i = 0; i < spells.size(); i++)
        if (spells[i]->getName() == spell->getName())
            return;
    spells.push_back(spell->clone());
}

void Warlock::forgetSpell(const string &name) {
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
        if ((*it)->getName() == name) {
            delete *it;
            spells.erase(it);
            return;
        }
}

void Warlock::launchSpell(const string &name, const ATarget &target) {
    for (size_t i = 0; i < spells.size(); i++)
        if (spells[i]->getName() == name)
            return spells[i]->launch(target);
}