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
float gold;

string nameT;
int agilityT, defenceT, damageT;
float priceT;
/*te z które kończą się na "T" służą do chwilowego przetrzymywania wartości przedmiotów, podczas przenoszenia ich z jednej tablicy do drugiej(np. ze sklepu do plecaka)*/
int agilityS, defenceS, damageS;
/*Te które kończą się na S mają za zadanie przetrzymywać sume wartości statystyk, które pochodzą z całego założonego ekwipunku, żeby to łatwo dodać do statystyk postaci (np. defenceS, sumuje obronę zbroi i tarczy itd.)*/
int tmp1;

void menu_ekwipunek();
/*funkcja obsługująca wszystko co związane z ekwipunkiem, sklepem, plecakiem*/
void statystyki_przedmiotow();
/*funkcja sumująca statystyki założonych przedmiotów i zapisująca je w xxxS*/


void wypis_wszystkich(int i, Item kat[]);
/*funkcja wyświetlająca na ekranie daną tablicę, napierw używamy którejś z funkcji wczytaj_xxx*/
Item* wczytaj_zalozone(int* i);
Item* wczytaj_w_plecaku(int* i);
Item* wczytaj_sklep(int* i);
/*wczytaj_xxxx, wszystkie działają tak samo, czyli pobierają z pliku .txt dane, które później są wyświetlane przez funkcje wypis_wszystkich*/
Item* usun(int* i, Item kat[]);
/*funkcja używana przy przenoszeniu przedmiotów z jednej tablicy do drugiej(tworzy nową tablice o jeden mniejszą od starej, przepisuje do niej potrzebne dane, a starą usuwa)*/
Item* zmniejsz(int* i, Item kat[]);
/*współpracuje z funkcją "usun"*/
Item* powieksz(int i, Item kat[]);
/*funkcja używana wewnątrz funkcji "dodaj", tworzy nową tablicę o jeden większą i przepisuje do niej dane ze starej, którą później usuwa*/
Item* dodaj(int* i, Item kat[]);
/*na koniec nowej tablicy utworzonej przez funkcje "powieksz" dodaje dane nowego przedmiotu*/
#endif
