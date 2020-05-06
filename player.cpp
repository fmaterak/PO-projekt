#include <unordered_set>
#include <cmath>
#include <fstream>

#include "area.hpp"
#include "player.hpp"
#include "creature.hpp"
#include "entity_manager.hpp"
#include "weapon.hpp"
#include "armor.hpp"

using namespace std;

Player::Player(string id,int hp, int strength,int defense, int agility, unsigned int xp, unsigned int level):
Creature("player",name,hp,strength,defense,agility,xp)
{
	this-> level=level;
	this->equippedArmor = nullptr;
	this->equippedWeapon = nullptr;
}

/* nie działa :/
Player::Player() : Player::Player("",0,0,0,0,0,1)
{}
*/
Player::Player()
{
	ifstream file("player.txt");
	while (file)
	{
		file>>/*this->id>>*/this->hp>>this->strength>>this->defense>>this->agility>>this->xp>>this->level;
	}
	file.close();
}

//Oblicza potrzebne xp do lvlup-a --- Do dopracowania
unsigned int Player::xpToLevel(unsigned int level)
{
	return (unsigned int)(1.5 * pow(this->level,3)); //TUTAJ
}
bool Player::levelUp()
{
	int skill_points;
	int choice;
	//rozdawanie statystyk
	if(this->xp < xpToLevel(this->level+1))
	{
		return false;
	}
	++level;
	skill_points=5; //Ilość do rozdania
	this->maxHp+=100; // <- Tutaj hp
	this->hp=this->maxHp;
	cout<<"Health grew to " << this->maxHp << "!\n";
	cout<<"Skill points: 5\n";
	cout<<"Choose upgrade: \n";
	cout<<"1.Strenght [+1]\n2. Defense [+1]\n3. Agility [+1]\n";

	//Wyeliminować echo przy stdin
	while(skill_points)
	{
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			cout<<"Strength "<<this->strength<<" -> ";
			this->strength+=1;
			cout<<this->strength<<endl;
			break;
		}
		case 2:
		{
			cout<<"Defense "<<this->defense<<" -> ";
			this->defense+=1;
			cout<<this->defense<<endl;
			break;
		}
		case 3:
		{
			cout<<"Agility "<<this->agility<<" -> ";
			this->agility+=1;
			cout<<this->agility<<endl;
			break;
		}
		default:
		{
			cout<<"MissClick\n";
			continue;
		}
		
	}
	skill_points--;
	}
	return true;
}

void Player::equipWeapon(Weapon* weapon)
{
	this->equippedWeapon = weapon;
	return;
}
void Player::equipArmor(Armor* armor)
{
	this->equippedArmor = armor;
	return;
}
