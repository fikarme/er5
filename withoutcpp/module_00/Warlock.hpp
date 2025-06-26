#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Warlock {
	private:
		string name;
		string title;

		Warlock();
		Warlock(const Warlock &);
		Warlock& operator=(const Warlock &rhs);


	public:
		Warlock(const string &name, const string &title) : name(name), title(title) {
			cout << this->name << ": This looks like another boring day." << endl;
		}

		~Warlock() {
			cout << this->name << ": My job here is done!" << endl;
		}

		const string &getName() const {
			return this->name;
		}

		const string &getTitle() const {
			return this->title;
		}

		void setTitle(const string &tit) {
			this->title = tit;
		}

		void introduce() const {
			cout << this->name << ": I am " << this->name << ", " << this->title << "!" << endl;
		}
};

#endif