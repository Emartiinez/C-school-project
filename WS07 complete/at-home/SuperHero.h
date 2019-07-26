#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"


// Workshop 7
// SuperHero.h
// Fabio Bernal
// 2018/07/14

namespace sict 
{
	class SuperHero : public Hero
	{
		char SuperHero_Name[MAX_NAME];
		int SuperHero_Health;
		int SuperHero_attack;
		int Power_Bonus_attack;
		int Power_Bonus_defense;

		public:
			SuperHero();
			SuperHero(const char* SP_name, int hp, int dmg, int super_dmg, int super_Defense);


			int attackStrength() const;
			int defend() const;
			void Hpreduction(int attack);


	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
	void Super_damage(SuperHero& A, SuperHero& B);

}

#endif