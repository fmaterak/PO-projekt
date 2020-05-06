#include <string>
#include <cstdlib>

#include "creature.hpp"
#include "entity.hpp"
#include "inventory.hpp"
#include "entity_manager.hpp"

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
/* ~Hmmm~
Creature::Creature(0, 0, 0, 0, 0)
{
	this->load;
}
*/
int Creature::attack(Creature* target)
{
	// Damage done
	int damage = 0;
	
	if(double(rand()) / RAND_MAX  > target->agility/*dodać zależność*/)
	{
		// Atak
		int attack = this->strength + (this->equippedWeapon == nullptr ? 0 : this->equippedWeapon->damage);
		// Obrona
		int defense = target->defense + (target->equippedArmor == nullptr ? 0 : target->equippedArmor->defense);
		// Unik - nieukończone
		int dodge = target->agility;

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

// Losuj statystyki przeciwnika
void Creature::enemy(int room)
{
	int a = room; // <- przelicznik trudności/pomieszczenie
	int b=3; // <- zakres losowania (np. str 0-3)
	//this->id="enemy";

	// Do dopracowania
	this->hp = rand() % b + (5*a+1);
	this->maxHp = this->hp;
	this->strength = rand() % b + (a+1);
	this->defense = rand() % b + (a+1);
	this->agility = rand() % b + (a+1);
	this->xp = this->hp + 5*(this->strength); // tu szczególnie
}
