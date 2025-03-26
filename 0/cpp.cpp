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
        Warlock(const Warlock& rhs);
        Warlock &operator=(const Warlock& rhs);
    public:
        const string &getName();
        const string &getTitle();
        void setTitle(const string &newTitle)
}

#endif

Warlock::Warlock(const string &name, const string &title) : name(name), title(title) {
    cout << name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock() {
    cout << name << ": My job here is done!" << endl;
}

const string &Warlock::getName() const {
    return name;
}

const string &Warlock::getTitle() const {
    return title;
}

void Warlock::setTitle(const string &newTitle) {
    title = newTitle;
}

void Warlock::introduce() const {
    cout << name << ": I am " << name << ", " << title << "!" << endl;
}

int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}

// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, Mistress of Magma!$
// Richard - Mistress of Magma$
// Jack: This looks like another boring day.$
// Jack: I am Jack, the Long!$
// Jack: I am Jack, the Mighty!$
// Jack: My job here is done!$
// Richard: My job here is done!$
// ~$