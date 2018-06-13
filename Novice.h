#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "Character.h"

using namespace std;

class Novice : public Character
{
private:
	//will be incremented as object levels
	int luck = 1;
public:
	///very similar functions to the other header files
	Novice();
	Novice(string);
	int getAttack();
	//new factor for the weakest character
	int getluck() { return luck; }
	void updateXP(int);
	void updateHP(int dmg) { HP -= dmg; }
	void print();
};

Novice::Novice() {
	setname("");
	setMaxHP(80);
}

Novice::Novice(string n) {
	setname(n);
	setMaxHP(80);
	HP = MaxHP;
}

int Novice::getAttack() {
	//srand((time(0)));
	////att is the max hit a character can do
	attack = (1 + rand() % 10) + luck;

	return attack;
}
///character will level up luck as an accumulator if it wins battles in main source cpp
void Novice::updateXP(int mpts) {
	//srand((time(0)));
	exp += mpts;
	if (exp >= maxcap) {
		level++;
		maxcap += 10;
		MaxHP += 10;
		///always heal after leveling up....
		luck += 3 + rand() & 3;
		heal();
	}
}

void Novice::print() {
	cout << "Name: " << getname() << "  HP: " << getHP() << "  Exp: " << getexp() << "/" << getmaxcap() << " Luck: " << getluck() << endl;
}
