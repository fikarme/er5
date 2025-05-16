#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Warlock {
private:
    string name;
    string title;
    Warlock();
    Warlock(const Warlock &cpy);
    Warlock &operator=(const Warlock &rhs);
public:
    ~Warlock()
    Warlock(const string & name, const string & title);
    const string & getName() const;
    const string & getTitle() const;
    void setTitle(const string & newTitle);
    void introduce() const;
}

#endif