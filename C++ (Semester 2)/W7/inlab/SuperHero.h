/**********************************************************^M
///////////////////////////////////////////////////////////
// Workshop 7: Derived Classes
// SuperHero.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/
#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		unsigned int sh_bonus;
		unsigned int sh_defend;
	public:
		SuperHero();
		SuperHero(const char* name, unsigned int health, unsigned int strength, unsigned int bonus, unsigned int defend);
		bool isEmpty() const;
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
