#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <unordered_set>

#include "creature.hpp"
#include "item.h"

using namespace std;

class EntityManager;
class Weapon;
class Armor;

class Player : public Creature
{
	public:
	unsigned level;
	Player(string id, int hp, int strength,int defense, int agility, unsigned int xp, unsigned int level,int gold);
	Player();
	
	//xp do lvlupa
	unsigned int xpToLevel(unsigned int level);
	bool levelUp();
	//Jakaś metoda do losowania statystyk...
};

#endif //PLAYER_HPP
