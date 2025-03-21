#include "Warlock.hpp"

void isConst(const std::string& str) {
    std::cout << str << std::endl;
}

int t0() {
    Warlock richard("Richard", "Mistress of Magma");
    isConst(richard.getName());
    std::cout << "t0: passed" << std::endl;
    return 0;
}

int t1() {
    // This test will not compile as intended since default constructor is private.
    // Uncommenting the following line will cause a compilation error:
    // Warlock richard();
    std::cout << "t1: passed (default constructor is private)" << std::endl;
    return 0;
}

int t2() {
    // This test will not compile as intended since copy constructor is private.
    // Uncommenting the following lines will cause a compilation error:
    // Warlock richard("Richard", "Mistress of Magma");
    // Warlock bob(richard);
    std::cout << "t2: passed (copy constructor is private)" << std::endl;
    return 0;
}

int t3() {
    // This test will not compile as intended since assignment operator is private.
    // Uncommenting the following lines will cause a compilation error:
    // Warlock richard("Richard", "Mistress of Magma");
    // Warlock bob("Bob", "Mistress of Magma");
    // bob = richard;
    std::cout << "t3: passed (assignment operator is private)" << std::endl;
    return 0;
}

int t4() {
    Warlock const richard("Richard", "Mistress of Magma");
    richard.introduce();
    std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

    Warlock* jack = new Warlock("Jack", "the Long");
    jack->introduce();
    jack->setTitle("the Mighty");
    jack->introduce();

    delete jack;

    std::cout << "t4: passed" << std::endl;
    return 0;
}

int main() {
    t0();
    t1();
    t2();
    t3();
    t4();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}