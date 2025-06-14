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
    ~Warlock();
    Warlock(const string &name, const string &title);
    const string &getName() const;
    const string &getTitle() const;
    void setTitle(const string &newTitle);
    void introduce() const;
};

Warlock::Warlock(const string & name, const string & title) : name(name), title(title) {
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

int main() {
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  cout << richard.getName() << " - " << richard.getTitle() << endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;
}
