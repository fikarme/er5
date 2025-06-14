#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"

using std::string;
using std::cout;
using std::endl;

class ASpell;

class ATarget {
protected:
    string type;
public:
    ATarget();
    ATarget(const string &type);
    ATarget(const ATarget &cpy);
    ATarget &operator=(const ATarget &rhs);
    virtual ~ATarget();

    const string &getType() const;
    virtual ATarget *clone() const = 0;
    void getHitBySpell(const ASpell &spell) const;
};

#endif
