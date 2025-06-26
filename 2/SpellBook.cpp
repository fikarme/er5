#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	map<string, ASpell*>::iterator it = spells.begin();
	while (it != spells.end()) {
		delete it->second;
		it++;
	}
	spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const string& spellName) {
	map<string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end()) {
		delete it->second;
		spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(const string& spellName) {
	map<string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end())
		return it->second->clone();
	return NULL;
}
