#include <cmath>
#include <iostream>
#include <fstream>

#include "player.hpp"
#include "creature.hpp"
#include "item.hpp"

using namespace std;

//Oblicza potrzebne xp do lvlup-a --- Do dopracowania
Player::Player(string id, int hp, int strength,int defense, int agility, unsigned int xp, unsigned int level, unsigned int gold):
Creature(id, hp, strength, defense, agility, xp, gold)
{
	this->level=level;
}
unsigned int Player::xpToLevel(unsigned int level)
{
	return (unsigned int)(1.5 * pow(level,3)); //TUTAJ
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
	this->maxHp+=5; // <- Tutaj hp
	this->hp=this->maxHp;
	cout<<"Zdrowie wzroslo do " << this->maxHp << "!\n";
	cout<<"Punkty statystyk do rozdania: 5\n";
	cout<<"Co ulepszyc? \n";
	cout<<"1.Sila [+1]\n2. Obrona [+1]\n3. Zrecznosc [+1]\n";

	//Wyeliminować echo przy stdin
	while(skill_points)
	{
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			cout<<"Sila "<<this->strength<<" -> ";
			this->strength+=1;
			cout<<this->strength<<endl;
			break;
		}
		case 2:
		{
			cout<<"Obrona "<<this->defense<<" -> ";
			this->defense+=1;
			cout<<this->defense<<endl;
			break;
		}
		case 3:
		{
			cout<<"Zrecznosc "<<this->agility<<" -> ";
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
