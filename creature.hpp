#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>
#include <string>

#include"entity.hpp"

class EntityManager;

class Creature : public Entity
{
	public:
    std::string name;
	int hp;
	int maxHp;
	int strength;
	int defense;
	int agility;
	unsigned int xp;

	Creature(std::string id, int hp, int strength,int defense, int agility,unsigned int xp);
	Creature();

	int attack(Creature* target);

	//losowanie statystyk wroga
	void enemy(int room);
};

#endif /* CREATURE_HPP */
