#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <string>
#include "entity.hpp"

class EntityManager;

class Creature
{
	public:
	std::string id;
	int hp;
	int maxHp;
	int strength;
	int defense;
	int agility;
	unsigned int xp;
	int gold;
	
	Creature(std::string id, int hp, int strength,int defense, int agility,unsigned int xp, int gold);
	
	int attack(Creature* target);
	int attack_fast(Creature* target);
	int attack_strong(Creature* target);
	int defend();
	int focus();
	int defend_enemy(Creature* target);
	int focus_enemy(Creature* target);
	
	//losowanie statystyk wroga
	void enemy(int room);
};

#endif /* CREATURE_HPP */
