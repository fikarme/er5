#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

// Forward-declare ATarget. This is a "promise" that the class exists.
class ATarget;

class ASpell {
protected:
	std::string name;
	std::string effects;

public:
	ASpell() : name(""), effects("") {}
	ASpell(const std::string &name, const std::string &effects) : name(name), effects(effects) {}
	ASpell(const ASpell &cpy) : name(cpy.name), effects(cpy.effects) {}
	virtual ~ASpell() {}

	ASpell &operator=(const ASpell &rhs) {
		if (this != &rhs) {
			this->name = rhs.name;
			this->effects = rhs.effects;
		}
		return *this;
	}

	// The assignment requires const reference for getters
	const std::string &getName() const { return name; }
	const std::string &getEffects() const { return effects; }

	virtual ASpell *clone() const = 0;

	// IMPORTANT: Only DECLARE launch() here. The implementation is in ATarget.hpp
	void launch(const ATarget &target) const;
};

#endif