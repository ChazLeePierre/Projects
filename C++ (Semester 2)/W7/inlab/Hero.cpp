/**********************************************************^M
///////////////////////////////////////////////////////////
// Workshop 7: Derived Classes
// Hero.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict {
	Hero::Hero() { // set object to safe empty state
		h_name[0] = '\0';
		h_health = 0;
		h_strength = 0;
	}

	Hero::Hero(const char* name, unsigned int health, unsigned int strength) { // initialize object if data is valid
		if (name[0] != '\0' && health != 0 && strength != 0) {
			strncpy(h_name, name, 40);
			h_name[41] = '\0';
			h_health = health;
			h_strength = strength;
		}
		else // if data is not valid, set to safe empty state
			*this = Hero();
	}

	void Hero::operator-=(int attack) { // deducts health from current object if current object is not in safe empty state
		if (attack > 0) {
			unsigned int damage = attack;
			h_health = damage > h_health ? 0 : h_health - damage;
		}
	}

	bool Hero::isAlive() const { // returns whether hero is alive
		return h_health > 0 ? true : false;
	}

	bool Hero::isEmpty() const { // returns whether object is in safe empty state
		return h_name[0] == '\0' && h_health == 0 && h_strength == 0 ? true : false;
	}

	int Hero::attackStrength() const { // returns current objects strength if object is not in a safe empty state
		return isEmpty() ? 0 : h_strength;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) { // inserts name of hero into the os stream and returns a reference to os
		hero.isEmpty() ? os << "No hero" : os << hero.h_name;
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) { // simulates a fight between two heroes and returns a reference to the winner
		const Hero *winner = nullptr;
		std::cout << "Ancient Battle! " << first << " vs " << second << " : ";
		Hero A = first;
		Hero B = second;
		unsigned int rounds;
		for (rounds = 0; A.isAlive() && B.isAlive() && rounds < 100; rounds++) {
			A -= B.attackStrength();
			B -= A.attackStrength();
		}
		winner = ((A.isAlive() && B.isAlive()) || A.isAlive()) ? &first : &second;
		std::cout << "Winner is " << *winner << " in " << rounds << " rounds." << std::endl;
		return *winner;
	}
}

