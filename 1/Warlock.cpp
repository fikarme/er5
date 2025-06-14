#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

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

void Warlock::learnSpell(ASpell *sname) {
    if (!sname)
        return;
    if (spells.count(sname->getName()) == 0)
        spells[sname->getName()] = sname->clone();
}

void Warlock::forgetSpell(const string &sname) {
    map<string, ASpell *>::iterator it = spells.find(sname);
    if (it != spells.end()) {
        delete it->second;
        spells.erase(it);
    }
}

void Warlock::launchSpell(const string &sname, const ATarget &target) {
    map<string, ASpell *>::iterator it = spells.find(sname);
    if (it != spells.end())
        it->second->launch(target);
}
