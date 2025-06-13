#ifndef TARGET_GENERATOR_HPP
#define TARGET_GENERATOR_HPP

#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private:
    std::map<std::string, ATarget*> targets;

    TargetGenerator(const TargetGenerator&);
    TargetGenerator &operator=(const TargetGenerator&);

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* target);
    void forgetTargetType(const std::string& targetType);
    ATarget* createTarget(const std::string& targetType);
};

#endif
