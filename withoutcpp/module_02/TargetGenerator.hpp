#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private:
	std::map<std::string, ATarget*> targets;

	TargetGenerator(const TargetGenerator &);
	TargetGenerator &operator=(const TargetGenerator &);

public:
	TargetGenerator() {}
	~TargetGenerator() {
		for (std::map<std::string, ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it) {
			delete it->second;
		}
		targets.clear();
	}

	void learnTargetType(ATarget *target) {
		if (target)
		{
			if (targets.count(target->getType()))
				delete targets[target->getType()];
			targets[target->getType()] = target->clone();
		}
	}

	void forgetTargetType(const std::string &type) {
		if (targets.count(type))
		{
			delete targets[type];
			targets.erase(type);
		}
	}

	ATarget *createTarget(const std::string &type) {
		if (targets.count(type))
			return targets[type]->clone();
		return NULL;
	}
};

#endif