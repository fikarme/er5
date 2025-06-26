#include "Warlock.hpp"
#include "SpellBook.hpp"

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
	if (spell)
		book.learnSpell(spell);
}

void Warlock::forgetSpell(const string &name) {
	book.forgetSpell(name);
}

void Warlock::launchSpell(const string &name, const ATarget &target) {
	ASpell* spell = book.createSpell(name);
	if (spell) {
		spell->launch(target);
		delete spell;
	}
}
