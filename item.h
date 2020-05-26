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
	int agility, defence, damage;
	float price;
};
int gold;

string nameT;
int agilityT, defenceT, damageT;
float priceT;

void menu_ekwipunek();

void wypis_wszystkich(int i, Item kat[]);
Item* wczytaj_zalozone(int* i);
Item* wczytaj_w_plecaku(int* i);
Item* wczytaj_sklep(int* i);
Item* usun(int* i, Item kat[]);
Item* zmniejsz(int* i, Item kat[]);
Item* powieksz(int i, Item kat[]);
Item* dodaj(int* i, Item kat[]);



#endif
