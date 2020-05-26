#include <string>
#include <cstdlib>

#include "creature.hpp"

using namespace std;

Creature::Creature(string id,int hp, int strength, int defense, int agility, unsigned int xp) : Entity(id)
{
	this->hp = hp;
	this->maxHp = hp;
	this->strength = strength;
	this->defense = defense;
	this->agility = agility;
	this->xp = xp;
}

int Creature::attack(Creature* target)
{
	// Damage done
	int damage = 0;

	if(double(rand()) > target->agility) // Dopasować rand
	{
		// Atak
		int attack = this->strength;
		// Obrona
		int defense = target->defense;
		// Przykładowe - do zrobienia
		// critical hit
		if(rand() % 32 == 0)
		{
			// Ignore defense and do damage in range [attack/2, attack]
			damage = attack / 2 + rand() % (attack / 2 + 1);
		}
		else
		{
			// Podstawa ataku
			int baseDamage = attack - defense / 2;
			// Damage in range [baseDamage/4, baseDamage/2]
			damage = baseDamage / 4 + rand() % (baseDamage / 4 + 1);
			// If the damage is zero then have a 50% chance to do 1 damage
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
	//większa szansa na unik
	this->agility*=1.5;
	if (double(rand()) > target->agility)
	{
		int attack=(this->strength)/2;
		int defense=target->defense;
		//krytyczny ? wstawić : lub nie;
		damage=attack-defense;
		target->hp -= damage;
	}
	return damage;
}
int Creature::attack_strong(Creature* target)
{
	int damage=0;
	//mniejsza szansa na unik
	this->agility*=0.5;
	if (double(rand())  > target->agility)
	{
		//większy atak
		int attack= (this->strength)*2;
		//ignorowanie części obrony przeciwnika?
		int defense=target->defense * 0.8;
		//większa szansa na krytyka?
		//tutaj wpisać

		damage=attack-defense;
		target->hp-=damage;
	}
	return damage;
}
int Creature::defend()
{
	int defend=0;
	this->defense*=2;
	defend= this->defense;
	return defend;
}
int Creature::focus()
{
	int focus=0;
	this->agility*=2;
	focus=this->agility;
	return focus;
}

//obrona i unik przeciwnika
int Creature::defend_enemy(Creature* target)
{
	int enemy_def=0;
	target->defense*=2;
	enemy_def=target->defense;
	return enemy_def;
}
int Creature::focus_enemy(Creature* target)
{
	int enemy_ag=0;
	target->agility*=2;
	enemy_ag=target->agility;
	return enemy_ag;
}

// Losuj statystyki przeciwnika
void Creature::enemy(int room)
{
	int a = room; // <- przelicznik trudności/pomieszczenie
	int b=3; // <- zakres losowania (np. str 0-3)
	//this->id="enemy";

	// Do dopracowania
	this->id="enemy";
	this->hp = rand() % b + (5*a+1);
	this->maxHp = this->hp;
	this->strength = rand() % b + (a+1);
	this->defense = rand() % b + (a+1);
	this->agility = rand() % b + (a+1);
	this->xp = this->hp + 5*(this->strength); // tu szczególnie
}
