#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	map<string, ATarget*>::iterator it = targets.begin();
	while (it != targets.end()) {
		delete it->second;
		it++;
	}
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target)
		if (targets.find(target->getType()) == targets.end())
			targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const string& targetType) {
	map<string, ATarget*>::iterator it = targets.find(targetType);
	if (it != targets.end()) {
		delete it->second;
		targets.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(const string& targetType) {
	map<string, ATarget*>::iterator it = targets.find(targetType);
	if (it != targets.end())
		return it->second->clone();
	return NULL;
}
