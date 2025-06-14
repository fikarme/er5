#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Warlock {
private:
    string name;
    string title;
    vector<ASpell *> spells;

    Warlock();
    Warlock(const Warlock &cpy);
    Warlock &operator=(const Warlock &);
public:
    ~Warlock();
    Warlock(const string &name, const string &title);
    const string &getName() const;
    const string &getTitle() const;
    void setTitle(const string &newTitle);
    void introduce() const;
    void learnSpell(ASpell *spell);
    void forgetSpell(const string &name);
    void launchSpell(const string &name, const ATarget &target);
};

#endif
