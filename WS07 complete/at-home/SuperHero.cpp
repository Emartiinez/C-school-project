// Workshop 7
// SuperHero.cpp
// Fabio Bernal
// 2018/07/14

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"SuperHero.h"
using namespace std;

namespace sict
{
	SuperHero::SuperHero() : Hero()
	{

		SuperHero_Name[0] = char(0);
		SuperHero_Health = 0;
		SuperHero_attack = 0;
		Power_Bonus_attack = 0;
		Power_Bonus_defense = 0;
	}

	SuperHero::SuperHero(const char* SP_name, int hp, int dmg, int super_dmg, int super_Defense) : Hero(SP_name, hp, dmg)
	{
		strncpy(SuperHero_Name, SP_name, MAX_NAME);
		SuperHero_Health = hp;
		SuperHero_attack = dmg;
		Power_Bonus_attack = super_dmg;
		Power_Bonus_defense = super_Defense;
	}

	int SuperHero:: attackStrength() const
	{ 
	/*	if (SuperHero_attack < 0)
		{
			return 0;
		}
		else
			return SuperHero_attack;*/
		return Power_Bonus_attack + SuperHero_attack;
	
	}
	int SuperHero::defend() const
	{
		if (SuperHero_Health < 0)
		{
			return 0;
		}
		else {
			return Power_Bonus_defense;
		}
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		SuperHero A = first;
		SuperHero B = second;
		int rounds = 0;

		const SuperHero *winner = nullptr;


		cout << "Super Fight! " << first << " vs " << second << " : ";

		while (A.isAlive() && B.isAlive() && rounds < max_rounds)
		{

			A -= (second.attackStrength()) - first.defend();
			B -= (first.attackStrength()) - second.defend();
			rounds++;
		}

		if (A.isAlive() && B.isAlive())
		{
			winner = &first;
		}
		else if (B.isAlive())
		{
			winner = &second;
		}
		else 
		{
			winner = &first;
		}
	
		cout << " Winner is " << *winner << " in " << rounds << " rounds. " << endl;

	
		return *winner;
	}



	void SuperHero::Hpreduction(int attack)
	{
		// if the attack is greater than the remaining health,
		// the hero dies and health = 0
		if (attack >= SuperHero_Health)
			SuperHero_Health = 0;
		else
			SuperHero_Health -= attack;
	}



	void Super_damage(SuperHero& A, SuperHero& B)
	{
		int dmg_A = B.attackStrength() - A.defend();
		int dmg_B = A.attackStrength() - B.defend();

		if (dmg_A < 1)
		{
			dmg_A = 1;
		}
		if (dmg_B < 1)
		{
			dmg_B = 1;
		}

		A.Hpreduction(dmg_A);
		B.Hpreduction(dmg_B);
	}
	

}