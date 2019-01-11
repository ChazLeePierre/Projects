/**********************************************************^M
///////////////////////////////////////////////////////////
// Workshop 7: Derived Classes
// Hero.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/
#pragma once
namespace sict {
 	int const max_rounds = 100; // max rounds
 	class Hero { 
 		char h_name[41]; // name
 		unsigned int h_health; // health
 		unsigned int h_strength; // strength
 	public: 
 		Hero(); // safe empty state
 		Hero(const char* name, unsigned int health, unsigned int strength); // initialize if data valid
 		void operator-=(int attack); // overloaded operator
 		bool isAlive() const; // check if hero is alive
 		bool isEmpty() const; // check if object is in a safe empty state
 		int attackStrength() const; // return the strength of hero
 		friend std::ostream& operator<<(std::ostream& os, const Hero& hero); // insert the name of a hero in the os stream
};	 
 	const Hero& operator*(const Hero& first, const Hero& second); // hero battle simulation
} 