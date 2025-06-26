#include "Warlock.hpp"

void isConst(const string &str) {
	cout << str << endl;
}

void t0() {
	Warlock richard("Richard", "Mistress of Magma");
	isConst(richard.getName());
	cout << "t0: passed" << endl;
}

void t1() {
	// This test will not compile as intended since default constructor is private.
	// Warlock richard();
}

void t2() {
	// This test will not compile as intended since copy constructor is private.
	// Warlock richard("Richard", "Mistress of Magma");
	// Warlock bob(richard);
}

void t3() {
	// This test will not compile as intended since assignment operator is private.
	// Warlock richard("Richard", "Mistress of Magma");
	// Warlock bob("Bob", "Mistress of Magma");
	// bob = richard;
}
void t4() {
	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	cout << richard.getName() << " - " << richard.getTitle() << endl;

	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	cout << "t4: passed" << endl;
}

int main() {
	t0();
	t1();
	t2();
	t3();
	t4();
	cout << "All tests passed!" << endl;
	return 0;
}