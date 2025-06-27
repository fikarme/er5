#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

using std::string;
using std::cout;
using std::endl;

class ATarget;

class ASpell {
protected:
	string name;
	string effects;
public:
	ASpell();
	ASpell(const string &name, const string &effects);
	ASpell(const ASpell &cpy);
	virtual ~ASpell();
	ASpell &operator=(const ASpell &rhs);

	const string &getName() const;
	const string &getEffects() const;
	virtual ASpell *clone() const = 0;
	void launch(const ATarget &target) const;
};

#endif
