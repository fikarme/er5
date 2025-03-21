#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "Fireball.hpp"

int t1() {
	Warlock richard("Richard", "foo");
	
	Fireball *fire = new Fireball();
	BrickWall* wall = new BrickWall();
	TargetGenerator tarGen;
	tarGen.learnTargetType(wall);
	richard.learnSpell(fire);
	const string name(fire->getName());
	const string effects(fire->getEffects());
	const string type(wall->getType());
	delete fire;
	delete wall;
	ATarget* target = tarGen.createTarget(type);
	richard.launchSpell(name, *target);

    cout << "t1: passed" << endl;
	
	fire = new Fireball();
	richard.learnSpell(fire);
	tarGen.learnTargetType(target);
	richard.forgetSpell(name);
	tarGen.forgetTargetType(type);
	cout << "have to be empy : ";
	richard.launchSpell(name, *target);
	if (tarGen.createTarget(type))
		cout << "is not...";
	cout << endl;

    cout << "t1.1: passed" << endl;
    return 0;
}

int t2() {
	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall model1;

	Polymorph* polymorph = new Polymorph();
	TargetGenerator tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball* fireball = new Fireball();

	richard.learnSpell(fireball);

	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);

    cout << "t2: passed" << endl;
    return 0;
}


int main() {
    t1();
    t2();
    cout << "main: passed" << endl;
    return 0;
}