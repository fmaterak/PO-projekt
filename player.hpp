#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <unordered_set>

#include "creature.hpp"
#include "item.hpp"

using namespace std;

class Player : public Creature
{
	public:
	unsigned int level;
	Player(string id, int hp, int strength,int defense, int agility, unsigned int xp, unsigned int level, unsigned int gold);
	Player(void);
	
	//xp do lvlupa
	unsigned int xpToLevel(unsigned int level);
	bool levelUp();
};

#endif //PLAYER_HPP
