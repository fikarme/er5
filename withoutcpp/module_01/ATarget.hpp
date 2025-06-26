#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp" // Include the full ASpell definition

class ATarget {
protected:
	std::string type;

public:
	ATarget() : type("") {}
	ATarget(const std::string &type) : type(type) {}
	ATarget(const ATarget &cpy) : type(cpy.type) {}
	virtual ~ATarget() {}

	ATarget &operator=(const ATarget &rhs) {
		if (this != &rhs) {
			this->type = rhs.type;
		}
		return *this;
	}

	const std::string &getType() const { return this->type; }

	virtual ATarget *clone() const = 0;

	// This can be fully defined here because ASpell is known from the include
	void getHitBySpell(const ASpell &spell) const {
		std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
	}
};

// IMPORTANT: Define ASpell::launch here.
// At this point, the compiler knows the full definitions of both ASpell and ATarget.
inline void ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}

#endif