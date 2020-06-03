#include <string>
#include <cstdlib>

#include "creature.hpp"

using namespace std;

Creature::Creature(string id ,int hp, int strength, int defense, int agility, unsigned int xp, unsigned int gold)
{
	this->id = id;
	this->hp = hp;
	this->maxHp = hp;
	this->strength = strength;
	this->defense = defense;
	this->agility = agility;
	this->xp = xp;
	this->gold = gold;
}

int Creature::attack(Creature* target)
{
	// Damage done
	int damage = 0;

	if(rand() % 100 > target->agility) // Dopasować rand
	{
		// Atak
		int attack = this->strength;
		// Obrona
		int defense = target->defense;
		// critical hit
		if(rand() % 32 == 0)
		{
			damage = attack - defense*0.5;
		}
		else
		{
			// Podstawa ataku
			damage = attack - defense;
			// 50% szans na 1dmg 
			if(damage < 1)
			{
				damage = rand() % 2;
			}
		}
		// Damage the target
		target->hp -= damage;
	}
	return damage;
}
int Creature::attack_fast(Creature* target)
{
	int damage=0;
	//większa szansa na unik??
	this->agility+=1;
	if (rand() % 100 > target->agility)
	{
		int attack=(this->strength)*0.75;
		int defense=target->defense;
		if(rand() % 32 == 0)
		{
			damage = attack - defense*0.5;
		}
		else
		{
			damage=attack-defense;
			if(damage < 1)
			{
				damage = rand() % 2;
			}
		}
		target->hp -= damage;
	}
	return damage;
}
int Creature::attack_strong(Creature* target)
{
	int damage=0;
	//mniejsza szansa na unik??
	this->agility-=1;
	if (rand() % 100 > target->agility)
	{
		//większy atak
		int attack= (this->strength)*1.5;
		//ignorowanie części obrony przeciwnika?
		int defense=target->defense * 1;
		if(rand() % 32 == 0)
		{
			damage = attack - 0.5*defense;
		}
		else
		{
			damage=attack-defense;
			if(damage < 1)
			{
				damage = rand() % 2;
			}
		}
		target->hp-=damage;
			
	}
	return damage;
}
int Creature::defend()
{
	int defend=0;
	this->defense+=2;
	defend= this->defense;
	return defend;
}
int Creature::focus()
{
	int focus=0;
	this->agility+=2;
	focus=this->agility;
	return focus;
}

//obrona i unik przeciwnika
int Creature::defend_enemy(Creature* target)
{
	int enemy_def=0;
	target->defense+=2;
	enemy_def=target->defense;
	return enemy_def;
}
int Creature::focus_enemy(Creature* target)
{
	int enemy_ag=0;
	target->agility+=2;
	enemy_ag=target->agility;
	return enemy_ag;
}
