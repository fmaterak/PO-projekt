#include <algorithm>
#include <iostream>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <map>

#include "item.h"
#include "creature.hpp"
#include "player.hpp"

// menu startowe
Player startGame();

// wyswietla przedmioty, statystyki
void dialogueMenu(Player& player);

int main()
{
	std::srand(std::time(nullptr));

	Player player = startGame();

	// gra trwa do zerwania petli
	while(1)
	{

			// jesli gracz przezyl otrzymuje doswiadczenie
			if(player.hp > 0)
			{
				unsigned int xp = 0;
				std::cout << "You gained " << xp << " experience!\n";
				player.xp += xp;
				// restart petli
				continue;
			}
			// jesli gracz ma 0 hp gra sie konczy
			else
			{
				std::cout << "\t----YOU DIED----\n    Game Over\n";
				return 0;
			}
		}

	return 0;
}

// tworzenie postaci lub wczytanie
Player startGame()
{
	std::cout << "Jakie imie chcesz wybrac?" << std::endl;
	std::string name;
	std::cin >> name;

	std::ifstream f((name).c_str());
	if(f.good())
	{
		f.close();

		// Return the player
	}
	else
	{
		f.close();
		int result;

		switch(result)
		{
			// Wojownik skupia sie na sile
			//case 1:
				//return Player(name, 15, 5, 4, 1.0/64.0, 0, 1, "Wojownik");

			// Bandyta skupia sie na zrecznosci
			//case 2:
				//return Player(name, 15, 4, 5, 1.0/64.0, 0, 1, "Bandyta");

			// case dla bezpieczenstwa
			//default:
				//return Player(name, 15, 4, 4, 1.0/64.0, 0, 1, "Normal");
		}
	}
}

void dialogueMenu(Player& player)
{
	// menu
	int result;
	std::cout << "Wybierz opcje (1 - przedmioty 2 - statystyki przedmiotow 3 - statystyki postaci)";

	switch(result)
	{
		// Wyswietlenie przedmiotow
		case 1:
			std::cout << "Przedmioty\n=====\n";

			std::cout << "----------------\n";
			break;
		// jesli nie ma przedmiotow prosi o zalozenie
		case 2:
		{
			std::cout << "Equipment\n=========\n";
			std::cout << "Armor: "
				<< std::endl;
			std::cout << "Weapon: "
				<< std::endl;

			int result2;

			// zbroja
			if(result2 == 1)
			{
				int userInput = 0;

				// sprawdzenie czy gracz ma zbroje
				int numItems;
				if(numItems == 0) break;

				while(!userInput)
				{
					// wybor
					std::cout << "Ktory przedmiot zalozyc?" << std::endl;
					std::cin >> userInput;

				}
			}
			// bron analogicznie do zbroji
			else if(result2 == 2)
			{
				int userInput = 0;

				while(!userInput)
				{
					std::cout << "Wybierz przedmiot?" << std::endl;
					std::cin >> userInput;
				}
			}
			std::cout << "----------------\n";
			break;
		}
		// Wyswietlenie statystyk
		case 3:
			std::cout << "Bohater\n=========\n";
			std::cout << player.name;
			std::cout << std::endl;

			std::cout << "Zdrowie:   " << player.hp << " / " << player.maxHp << std::endl;
			std::cout << "Sila: " << player.strength << std::endl;
			std::cout << "Zrecznosc:  " << player.agility << std::endl;
			std::cout << "Poziom:    " << player.level << " (" << player.xp;
			std::cout <<  " / " << player.xpToLevel(player.level+1) << ")" << std::endl;
			std::cout << "----------------\n";
			break;
		default:
			break;
	}

	return;
}
