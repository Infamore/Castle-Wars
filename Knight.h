#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "Character.h"

using namespace std;

class Knight : public Character
{
private:
	//more factors influencing damage
	int armor = 1;
	int wpnpower;
public:
	///very very very similar functions to the other header files
	Knight();
	Knight(string, int);
	int getAttack();
	int getwpn() { return wpnpower; }
	int getarmor() { return armor; }
	void updateXP(int);
	void updateHP(int dmg);
	void print();

};

Knight::Knight() {
	name = "";
	MaxHP = 120;
	wpnpower = 0;
}

Knight::Knight(string n, int power) {
	name = n;
	MaxHP = 120;
	HP = MaxHP;
	wpnpower = power;
}

int Knight::getAttack() {
	//srand((time(0)));
	////att is the max hit a character can do
	attack = (1 + rand() % 20) + wpnpower;

	return attack;
}
///exp for the knight is incremented with much higher hp and more armor to deflect damage, but harder to level up...
void Knight::updateXP(int mpts) {
	exp += (mpts - 1);
	if (exp >= maxcap) {
		level++;
		maxcap += 15;
		MaxHP += 15;
		armor++;
		///always heal after leveling up....
		heal();
	}
}

void Knight::updateHP(int dmg) {
	HP -= (dmg - (attack / dmg));
}

void Knight::print() {
	cout << "Name: " << getname() << "  HP: " << getHP() << "  Exp: " << getexp() << "/" << getmaxcap() << " Armor: " << getarmor() << " Weapon Power: " << getwpn() << endl;
}