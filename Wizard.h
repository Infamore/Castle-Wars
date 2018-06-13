#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "Character.h"

using namespace std;

class Wizard : public Character
{
private:
	//magic bonus for attack points
	int magebonus;
public:
	///get functions, constructors, and basic functions
	Wizard();
	Wizard(string, string);
	int getAttack();
	void updateXP(int);
	void updateHP(int dmg);
	int getbonus() { return magebonus; }
	void print();
};

Wizard::Wizard() {
	magebonus = 0;
	name = "";
	MaxHP = 100;
}

Wizard::Wizard(string n, string bns) {
	name = n;
	MaxHP = 100;
	HP = MaxHP;
	//as instructed in lab guide that either can influence the wizard attack points
	if (bns == "divine")
		magebonus = 5;
	if (bns == "arcane")
		magebonus = 2;
}

int Wizard::getAttack() {
	//srand((time(0)));
	////att is the max hit a character can do
	attack = (5 + rand() % 11) + magebonus;

	return attack;
}
///wizard updates exp and increases magic bonus and other attributes respecitvely
void Wizard::updateXP(int mpts) {
	exp += (mpts - 2);
	if (exp >= maxcap) {
		level++;
		maxcap += 12;
		MaxHP += 8;
		magebonus += 3;
		///always heal after leveling up....
		heal();
	}
}

void Wizard::updateHP(int dmg) {
	HP -= (dmg - (attack / dmg));
}

void Wizard::print() {
	cout << "Name: " << getname() << "  HP: " << getHP() << "  Exp: " << getexp() << "/" << getmaxcap() << " Magic Bonus: " << getbonus() << endl;
}