#ifndef ITEM_HPP
#define ITEM_HPP

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
	int price;
	
};


void menu_ekwipunek(int gold);
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
#endif //ITEM_HPP
