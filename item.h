#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Item
{
public:

	string name;
	int id, agility;
	float price;


	//Item(string n = "Brak nazwy", int i = 0, int a = 0, float p = 0)
	//{
	//	name = n;
	//	id = i;
	//	agility = a;
	//	price = p;
	//}
};

class Armor :public Item
{
public:

	int defense;


	//Armor( string n, int i, int a, float p, int d = 0)
	//:Item(n, i, a, p)
	//{
	//	defense = d;
	//}
};

class Weapon :public Item
{
public:

	int damage;


	//Weapon(string n, int i, int a, float p, int dm = 0)
	//	:Item(n, i, a, p)
	//{
	//	damage = dm;
	//}

};

class Shield :public Item
{
public:

	int defense;


	//Shield(string n, int i, int a, float p, int d1 = 0)
	//	:Item(n, i, a, p)
	//{
	//	defense = d1;
	//}
};

#endif