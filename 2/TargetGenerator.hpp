#ifndef TARGET_GENERATOR_HPP
#define TARGET_GENERATOR_HPP

#include <string>
#include <map>
#include "ATarget.hpp"
using std::string;
using std::map;

class TargetGenerator {
private:
	map<string, ATarget*> targets;

	TargetGenerator(const TargetGenerator&);
	TargetGenerator &operator=(const TargetGenerator&);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* target);
	void forgetTargetType(const string& targetType);
	ATarget* createTarget(const string& targetType);
};

#endif
