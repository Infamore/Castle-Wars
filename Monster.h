#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Monster
{
protected:
	int AC;
	int attack;
	int level;
	int HP;
	string name;
	
public:
	Monster() {};
	Monster(int, int, int, string);
	
	void print();
	///the boss will have different attack points then regular monsters
	int getbossatt();
	int getAC() { return AC; }
	int getlevel() { return level; }
	int getHP() { return HP; }
	string getname() { return name; }
	virtual void setvector(vector<Monster>);
	void random(vector<Monster>);
	void updateHP(int);
};
///standard parametrized constructor
Monster::Monster(int ac, int hp, int lvl, string n) {
	AC = ac;
	level = lvl;
	HP = hp;
	name = n;
}
///reiterated just in case....at least the virtual function works
void Monster::setvector(vector<Monster> CPU) {
	Monster Troglodyt(10, 10, 2, "Troglodyt");
	Monster OrcWarrior(15, 15, 3, "Orc Warrior");
	Monster Blkdragon(20, 20, 4, "Black Dragon");
	Monster goblin(5, 10, 1, "Goblin");
	CPU.push_back(Troglodyt);
	CPU.push_back(OrcWarrior);
	CPU.push_back(Blkdragon);
	CPU.push_back(goblin);
}

//prints for the boss and regular monsters for dialogue info
void Monster::print() {
	cout << getname() << " AC = " << getAC() << " level = " << getlevel() << " HP = " << getHP() << endl;
}


void Monster::random(vector<Monster> vect) {
	random_shuffle(vect.begin(), vect.end());
}

///basically the same as the other getattack functions...
int Monster::getbossatt() {
	//srand((time(0)));

	attack = (getAC() / 10) + (4 + rand() % 16);

	return attack;
}
///obvious....
void Monster::updateHP(int dmg) {
	HP -= dmg;
}