#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

using std::string;
using std::cout;
using std::endl;
using std::map;

class Warlock {
private:
    string name;
    string title;
    map<string, ASpell *> spells;

    Warlock();
    Warlock(const Warlock &cpy);
    Warlock &operator=(const Warlock &rhs);

public:
    Warlock(const string &name, const string &title);
    ~Warlock();

    const string &getName() const;
    const string &getTitle() const;
    void setTitle(const string &newTitle);
    void introduce() const;
    void learnSpell(ASpell *sname);
    void forgetSpell(const string &sname);
    void launchSpell(const string &sname, const ATarget &target);
};

#endif
