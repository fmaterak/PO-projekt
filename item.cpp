#include "item.h"
using namespace std;

void przypisanie()
{
	//Armor
	{
		Armor A1;
		A1.id = 1;
		A1.price = 20;
		A1.agility = 0;
		A1.name = "Boiled leather";
		A1.defense = 2;
	}
	{
		Armor A2;
		A2.id = 2;
		A2.price = 35;
		A2.agility = 0;
		A2.name = "Basic Armor";
		A2.defense = 7;
	}
	{
		Armor A3;
		A3.id = 3;
		A3.price = 50;
		A3.agility = -10;
		A3.name = "Iron Armor";
		A3.defense = 14;
	}
	//Weapon
	{
		Weapon W1;
		W1.id = 11;
		W1.price = 15;
		W1.agility = 2;
		W1.name = "Knife";
		W1.damage = 3;
	}
	{
		Weapon W2;
		W2.id = 12;
		W2.price = 28;
		W2.agility = 3;
		W2.name = "Sabre";
		W2.damage = 6;
	}
	{
		Weapon W3;
		W3.id = 13;
		W3.price = 43;
		W3.agility = 5;
		W3.name = "Short Sword";
		W3.damage = 13;
	}
	{
		Weapon W1l;
		W1l.id = 111;
		W1l.price = 18;
		W1l.agility = -1;
		W1l.name = "Rusty Spear";
		W1l.damage = 5;
	}
	//Shield
	{
		Shield S1;
		S1.id = 1111;
		S1.price = 15;
		S1.agility = 0;
		S1.name = "Lid";
		S1.defense = 2;
	}
	{
		Shield S2;
		S2.id = 1112;
		S2.price = 22;
		S2.agility = -4;
		S2.name = "Demaged Shield";
		S2.defense = 4;
	}
}
