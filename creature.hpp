#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <string>
//#include "entity.hpp"
//#include "inventory.hpp"

class EntityManager;

class Creature : public Entity
{
public:
	int hp;
	int maxHp;
	int strength;
	int defense;
	int agility;
	unsigned int xp;

	Creature(std::string id, int hp, int strength, int defense, int agility, unsigned int xp);
	Creature();
	int attack(Creature* target);
	int attack_fast(Creature* target);
	int attack_strong(Creature* target);
	int defend();
	int focus();
	//losowanie statystyk wroga
	void enemy(int room);
};

#endif /* CREATURE_HPP */
