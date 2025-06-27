#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
private:
	std::map<std::string, ASpell*> spells;

	SpellBook(const SpellBook &);
	SpellBook &operator=(const SpellBook &);

public:
	SpellBook() {}
	~SpellBook() {
		for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it) {
			delete it->second;
		}
		spells.clear();
	}

	void learnSpell(ASpell *spell) {
		if (spell)
		{
			if (spells.count(spell->getName()))
				delete spells[spell->getName()];
			spells[spell->getName()] = spell->clone();
		}
	}

	void forgetSpell(const std::string &name) {
		if (spells.count(name))
		{
			delete spells[name];
			spells.erase(name);
		}
	}

	ASpell *createSpell(const std::string &name) {
		if (spells.count(name))
			return spells[name]->clone();
		return NULL;
	}
};

#endif