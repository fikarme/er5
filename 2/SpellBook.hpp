#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"
using std::string;
using std::map;

class SpellBook {
private:
	map<string, ASpell*> spells;

	SpellBook(const SpellBook&);
	SpellBook &operator=(const SpellBook&);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell* spell);
	void forgetSpell(const string& spellName);
	ASpell* createSpell(const string& spellName);
};

#endif
