#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "Monster.h"
#include "Wizard.h"
#include "Knight.h"
#include "Novice.h"
#include "Character.h"

using namespace std;
///declaring a ton of functions
void battle(vector<Monster>&, vector<Character*>&);
void maketeam(vector<Character*>&);
void listteam(vector<Character*>&);
void mainheal(vector<Character*>&);
///a print function that requires parameters so it can display the round and the current miles
void mainmenu(int, int);
void finalboss(vector<Character*>&, int&, int&, int&);
void setvector(vector<Monster>&);

void main()
{
	srand((time(0)));
	//base class vector pointer
	vector<Character*> goodguys;
	//regular class vector
	vector<Monster> badguys;
	int miles = 1000;
	///random variable that determines if the final boss was successfully defeated
	int trivial = 0;
	//round counter
	int round = 1;
	//used for inputs
	int choice;
	char repeat;

	cout << "The Dark Lord is " << miles << " miles away from the kingdom. Create a team and build up strength to defeat him before it's too late!\n\n";
	do
	{
		///use this function to make the team first then use that to play the game
		maketeam(goodguys);
		//if the boss hasn't already reached the kingdom
		while (miles != 0) {
			//after all options in the menu have been ran through and the team has been defeated, miles = 0 for an automatic termination
			if (goodguys.size() == 0) {
				miles = 0;
				break;
			}
			mainmenu(miles, round);
			cin >> choice;
			///miles is technically an accumulator and the boss will approach the kingdom 100 miles each round
			switch (choice)
			{
			case 1:
				battle(badguys, goodguys);
				miles -= 100;
				break;
			case 2:
				mainheal(goodguys);
				miles -= 100;
				break;
			case 3:
				listteam(goodguys);
				miles -= 100;
				break;
			case 4:
				finalboss(goodguys, miles, round, trivial);
				break;
			case 5:
				//does nothing
				miles -= 100;
				break;
			case 6:
				//automatically sets boss to victory
				miles = 0;
				break;

			}
			//increment the day
			round++;

		}
		///this particular if nest will decide the situation just before restarting the game
		//obviously, when miles = 0 game is over
		if (miles == 0) {
			//clear vectors to start fresh
			goodguys.clear();
			badguys.clear();
			//trivial variable needed to determine who if whether the player or boss won or not at the end
			if (trivial == 0)
				cout << "The Dark lord has reached the kingdom, play again? (y/n)";
			//player won
			if (trivial == 1)
				cout << "Play again? (y/n)";
			cin >> repeat;
			cout << endl;
			if (toupper(repeat) == 'Y') {
				//reset miles and round of course
				miles = 1000;
				round = 1;
			}
		}
	} while (toupper(repeat) == 'Y');

	system("PAUSE");
}

void mainmenu(int m, int r) {
	cout << "Day " << r << endl;
	cout << "The Dark Lord is " << m << " miles away from the kingdom.\n";
	cout << "1. Explore the wilderness\n";
	cout << "2. Rest\n";
	cout << "3. Character Stats\n";
	cout << "4. Confront the Dark Lord\n";
	cout << "5. End day (next round)\n";
	cout << "6. Quit\n";
}

void mainheal(vector<Character*> &goodboys) {
	//for loop to run through vector as the point uses an arrow operator to use the heal function so every member is healed
	for (int i = 0; i < goodboys.size(); i++)
		goodboys[i]->heal();
	cout << "Your team was fully restored\n";
}

void battle(vector<Monster> &badboys, vector<Character*> &goodboys) {
	///spaghetti code....
	//determines the user input 
	string manlytest;
	//monster vector will have new objects added
	setvector(badboys);
	///algorithm utilized for random encounters
	random_shuffle(badboys.begin(), badboys.end());
	///output and basic get functions to display monster stats
	cout << "A " << badboys[0].getname() << "appeared!\n";
	cout << "Stats: " << "AC = " << badboys[0].getAC() << " level = " << badboys[0].getlevel() << " HP = " << badboys[0].getHP() << endl;
	cout << "Fight or Flee? ";
	cin >> manlytest;
	///if user decides to battle
	//note that [0] subscript is used to refer to the beginning of the vector as the vector will be randomized anyway
	if (manlytest == "Fight") {
		///random algorithm
		random_shuffle(goodboys.begin(), goodboys.end());
		//we choose the new first element of the vector
		cout << "Oh no, the enemy attacked " << goodboys[0]->getname() << endl;
		//if the monster from the randomized monster vector has a higher AC than the attack points of good guys, the latter loses...
		if (badboys[0].getAC() > goodboys[0]->getAttack()) {
			///details
			cout << goodboys[0]->getname() << " was to weak!\n";
			goodboys[0]->updateHP(badboys[0].getAC());
			cout << goodboys[0]->getname() << " now has " << goodboys[0]->getHP() << " HP!\n\n";
			///if the object in the team vector loses and has depleted HP, it is erased from the vector
			if (goodboys[0]->getHP() <= 0) {
				cout << "Noooo " << goodboys[0]->getname() << " was defeated and cut from the team!\n\n";
				goodboys.erase(goodboys.begin()); ///well, [0] is the beginning of the vector right?
			}
		}

		else
		{
			///basically if the player's vector object wins
			cout << goodboys[0]->getname() << " endured the attack and won the battle!\n";
			cout << "Everyone gained " << badboys[0].getAC() << " experience points!\n";
			cout << "Check character stats in the main menu to view your team\n\n";
			///update exp
			for (int i = 0; i < goodboys.size(); i++) 
				goodboys[i]->updateXP(badboys[0].getAC());
			
		}

	}
	///self-explanatory
	else if (manlytest == "Flee") {
		cout << "You fled the scene!\n";
	}

}


void maketeam(vector<Character*>& ptr) {
	char unit, repeat;
	int wpn;
	string name, magebns;
	///this maketeam function uses a lot of format from the guide provided in canvas
	do
	{
		cout << "Which units would you like to add to your team? (N = Novice, K = Knight W = Wizard)";
		cin >> unit;
		///switch statement used to create new objects according to each character derived class
		//ptr pushes back an allocated object to the back of the vector
		switch (unit)
		{
		case 'n':
		case 'N':
			cout << "Enter the name:";
			cin.ignore();
			getline(cin, name);
			ptr.push_back(new Novice(name));
			break;
		case 'k':
		case 'K':
			cout << "Enter the name and weapon power:";
			cin >> name >> wpn;
			ptr.push_back(new Knight(name, wpn));
			break;

		case 'w':
		case 'W':
			cout << "Enter the name and either divine or arcane (5, 2)";
			cin >> name >> magebns;
			ptr.push_back(new Wizard(name, magebns));
			break;
		}
		cout << "Make another character? (y/n)";
		cin >> repeat;
		cout << endl << endl;
	} while (toupper(repeat) == 'Y');
	
}

void listteam(vector<Character*> &goodboys) {
	///if statement to confirm the vector is filled
	if (goodboys.size() != 0) {
		for (int i = 0; i < goodboys.size(); i++)
			goodboys[i]->print();
	}
	else
	{
		//can't let the function print out nothing
		cout << "Your team is empty...\n";
	}
	cout << endl;
}

void finalboss(vector<Character*> &goodboys, int& m, int& r, int& trivia) {
	Monster Darklord(100, 1000, 9000, "Dark Lord");
	cout << "The Boss has appeared!\n";
	cout << "Stats: "; 
	///darklord has its own print function in the monster class
	Darklord.print();
	//while the final boss is still in battle
	while (Darklord.getHP() > 0) {
		cout << "You attacked first!\n";
		///update the boss's HP
		for (int i = 0; i < goodboys.size(); i++) {
			Darklord.updateHP(goodboys[i]->getAttack());
			cout << goodboys[i]->getname() << " deals " << goodboys[i]->getattack() << " damage!\n";

		}

		cout << "The boss now has " << Darklord.getHP() << endl;
		cout << "Now the Dark lord chooses a victim in your team...\n";
		///random shuffle algorithm to randomly choose a character in the vector
		random_shuffle(goodboys.begin(), goodboys.end());
		cout << "Oh no, the enemy attacked " << goodboys[0]->getname() << endl;
		///determines who wins the battle
		if (Darklord.getbossatt() > goodboys[0]->getAttack()) {
			cout << goodboys[0]->getname() << " was to weak and lost " << Darklord.getbossatt() << " HP!\n";
			goodboys[0]->updateHP(Darklord.getbossatt());
			cout << goodboys[0]->getname() << " now has " << goodboys[0]->getHP() << " HP!\n\n";
			///same concept in the battle function to see who wins and the consequences for the player losing
			if (goodboys[0]->getHP() <= 0) {
				cout << "Noooo " << goodboys[0]->getname() << " was defeated and cut from the team!\n";
				goodboys.erase(goodboys.begin()); ///well, [0] is the beginning of the vector right?
				cout << "Your team now has:\n\n";
				//stating the team again to remind the user of what they have
				listteam(goodboys);
			}

	}
		else
		{
			///if the player was successful
			cout << "Fortunately " << goodboys[0]->getname() << " endured the attack and deals some damage back to the boss!\n";
			///damage is dealt to the final boss
			Darklord.updateHP(goodboys[0]->getAttack());
			cout << "The Dark Lord now has " << Darklord.getHP() << endl << endl;
		}
		
		if (goodboys.size() == 0) {
			//proves for sure when the final boss wins because vector does not hold anymore characters
			cout << "You lost and the Dark lord has ravaged the kingdom...\n";
			//therefore trivia is 0 making the end of the do loop logical
			trivia = 0;
				break;
		}
	}
	//if the player wins, trivia is 1 and makes the end of the do loop logical
	if (Darklord.getHP() <= 0) {
		cout << "You win!\n";
		m = 0;
		r = 0;
		trivia = 1;
	}
}
///as explained and used above, setvector creates new monster objects using parametrized objects and pushes them back to the vector
void setvector(vector<Monster> &CPU) {
	Monster Troglodyt(10, 10, 2, "Troglodyt");
	Monster OrcWarrior(15, 15, 3, "Orc Warrior");
	Monster Blkdragon(20, 20, 4, "Black Dragon");
	CPU.push_back(Troglodyt);
	CPU.push_back(OrcWarrior);
	CPU.push_back(Blkdragon);
}