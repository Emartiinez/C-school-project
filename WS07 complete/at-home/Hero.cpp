// Workshop 7
// Hero.h
// Fabio Bernal
// 2018/07/12
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;
namespace sict
{
	void Hero::set()
	{
		hero_name[0] = char(0);
		health = 0;
		attack = 0;

	}
	void Hero::set(const char name[], int hp, int dmg)
	{

		if (name != nullptr)
		{
			strncpy(hero_name, name, MAX_NAME);
			health = hp;
			attack = dmg;
		}
	}

	Hero::Hero()
	{
		set();
	}

	Hero::Hero(const char name[], int hp, int dmg)
	{
		set(name, hp, dmg);
	}


	void Hero ::operator -= (int dmg)
	{
		if (dmg > 0)
		{
			health -= dmg;
			{ if (health <= 0)
				health = 0;
			}
		}
	}

	bool Hero::isAlive() const
	{
		bool alive;

		if (health > 0)

		{
			alive = true;
		}
		else
		{
			alive = false;
		}
		return alive;
	}

	int Hero::attackStrength()const
	{
		if (health == 0 && hero_name == nullptr && attack == 0)

		{
			return 0;
		}
		else
		{
			return attack;
		}
	}

	std ::ostream& operator << (std ::ostream& os , const Hero & hero)
	{
		if (hero.health == 0 && hero.attack==0)
		{
			os << " No hero ";
		}
		else
		{
			os << hero.hero_name;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second)

	{
		cout << "Ancient Battle! " << first << " vs " << second << " : ";

		Hero A = first;
		Hero B = second;
		int rounds = 0;
		
		const Hero *winner = nullptr;

		

		while (A.isAlive() && B.isAlive() && rounds < max_rounds)
		{
			A -= (B.attackStrength());
			B -= (A.attackStrength());
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
		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;
		return *winner;
	
	}
}