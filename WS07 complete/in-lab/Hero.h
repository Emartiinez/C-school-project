#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_HERO_H
#define SICT_HERO_H
// Workshop 7
// Hero.h
// Fabio Bernal
// 2018/07/12

namespace sict
{


	const int max_rounds = 100;
	const int MAX_NAME = 41;
	class Hero
	{
	private:
		char hero_name[MAX_NAME];
		int health;
		int attack;
	

		void set();
		void set(const char name[], int hp, int attack);

	public:
		Hero();
		Hero(const char name[], int hp, int attack);
		      
		void operator -= (int attack);
		bool isAlive() const;
		int attackStrength() const;

		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	
	const Hero& operator*(const Hero& first, const Hero& second);








}
#endif