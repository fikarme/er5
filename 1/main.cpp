#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

void isConst(const string& str) {
    cout << str << endl;
}

void t0() {
    // ASpell spell;
    // ATarget target;
    Dummy richard1;
    isConst(richard1.getType());
    Fwoosh richard2;
    isConst(richard2.getName());

    Warlock richard("Richard", "the Titled");

    Dummy bob;
    Fwoosh* fwoosh = new Fwoosh();

    richard.learnSpell(fwoosh);

    richard.introduce();
    richard.launchSpell("Fwoosh", bob);

    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", bob);

    delete fwoosh;
    cout << "t0: passed" << endl;
}

void t1() {
    Warlock const richard("Richard", "Mistress of Magma");
    richard.introduce();
    cout << "t1: passed" << endl;
}

void t2() {
    Warlock* jack = new Warlock("Jack", "the Long");
    jack->introduce();
    delete jack;
    cout << "t2: passed" << endl;
}

void t3() {
    Warlock const richard("Richard", "Mistress of Magma");
    cout << richard.getName() << " - " << richard.getTitle() << endl;
    cout << "t3: passed" << endl;
}

void t4() {
    Warlock* jack = new Warlock("Jack", "the Long");
    jack->setTitle("the Mighty");
    jack->introduce();
    delete jack;
    cout << "t4: passed" << endl;
}

void t5() {
    Warlock const richard("Richard", "Mistress of Magma");
    isConst(richard.getName());
    isConst(richard.getTitle());
    cout << "t5: passed" << endl;
}

void t6() {
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
  cout << "t6: passed" << endl;
  delete fwoosh;
}

int main() {
    t0();
    t1();
    t2();
    t3();
    t4();
    t5();
    t6();
    cout << "All tests passed!" << endl;
}
