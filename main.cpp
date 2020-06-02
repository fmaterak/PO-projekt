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
//#include "weapon.hpp"
//#include "armor.hpp"
//#include "inventory.hpp"
#include "creature.hpp"
#include "player.hpp"
#include "battle.hpp"

// menu startowe
Player startGame();

// wyswietla przedmioty, statystyki
void dialogueMenu(Player& player);

int main()
{
	std::srand(std::time(nullptr));

	Player player = startGame();

	// gra trwa do zerwania petli
	while (1)
	{
		// autozapis
		player.save(&entityManager);

		// sprawdzenie czy sa przeciwnicy
		if (areaPtr->creatures.size() > 0)
		{
			// wektor wskaznikow na przeciwnikow
			std::vector<Creature*> combatants;
			std::cout << "Zostales zaatakowany przez: ";
			for (int i = 0; i < areaPtr->creatures.size(); ++i)
			{
				Creature* c = &(areaPtr->creatures[i]);
				combatants.push_back(c);
				std::cout << c->name << (i == areaPtr->creatures.size() - 1 ? "!\n" : ", ");
			}
			// dodanie gracza
			combatants.push_back(&player);
			// rozpoczecie walki
			Battle battle(combatants);
			battle.run();

			// jesli gracz przezyl otrzymuje doswiadczenie
			if (player.hp > 0)
			{
				unsigned int xp = 0;
				for (auto creature : areaPtr->creatures) xp += creature.xp;
				std::cout << "You gained " << xp << " experience!\n";
				player.xp += xp;
				// usuniecie przeciwnikow
				areaPtr->creatures.clear();
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
	if (f.good())
	{
		f.close();
		Player player = Player(saveData, areaData, &entityManager);

		// Return the player
		return player;
	}
	else
	{
		f.close();
		int result = Dialogue(
			"Choose your class",
			{ "Wojownik", "Bandyta" }).activate();

		switch (result)
		{
			// Wojownik skupia sie na sile
		case 1:
			return Player(name, 15, 5, 4, 1.0 / 64.0, 0, 1, "Wojownik");

			// Bandyta skupia sie na zrecznosci
		case 2:
			return Player(name, 15, 4, 5, 1.0 / 64.0, 0, 1, "Bandyta");

			// case dla bezpieczenstwa
		default:
			return Player(name, 15, 4, 4, 1.0 / 64.0, 0, 1, "Normal");
		}
	}
}

void dialogueMenu(Player& player)
{
	// menu
	int result;
	std::cout << "Wybierz opcje (1 - przedmioty 2 - statystyki przedmiotow 3 - statystyki postaci)";
	cin >> result;

	switch (result)
	{
		// Wyswietlenie przedmiotow
	case 1:
		//std::cout << "Przedmioty\n=====\n";
		//player.inventory.print();
		//std::cout << "----------------\n";
		menu_ekwipunek();

		break;
	case 2:
	{
		statystyki_przedmiotow();
		cout << "Obrona pochodzaca z zalozonych przedmiotw: " << defenceS << endl;
		cout << "Atak pochodzacy z zalozonych przedmiotw: " << damageS << endl;
		cout << "Zrecznosc pochodzaca z zalozonych przedmiotw: " << agilityS << endl;
		/*std::cout << "Equipment\n=========\n";
		std::cout << "Armor: "
			<< (player.equippedArmor != nullptr ?
				player.equippedArmor->name : "Nothing")
			<< std::endl;
		std::cout << "Weapon: "
			<< (player.equippedWeapon != nullptr ?
				player.equippedWeapon->name : "Nothing")
			<< std::endl;

		int result2 = Dialogue(
			"",
			{ "Equip Armor", "Equip Weapon", "Close" }).activate();

		// zbroja
		if (result2 == 1)
		{
			int userInput = 0;

			// sprawdzenie czy gracz ma zbroje
			int numItems = player.inventory.print<Armor>(true);
			if (numItems == 0) break;

			while (!userInput)
			{
				// wybor
				std::cout << "Ktory przedmiot zalozyc?" << std::endl;
				std::cin >> userInput;

				if (userInput >= 1 && userInput <= numItems)
				{
					player.equipArmor(player.inventory.get<Armor>(userInput - 1));
				}
			}
		}
		// bron analogicznie do zbroji
		else if (result2 == 2)
		{
			int userInput = 0;
			int numItems = player.inventory.print<Weapon>(true);

			if (numItems == 0) break;

			while (!userInput)
			{
				std::cout << "Wybierz przedmiot?" << std::endl;
				std::cin >> userInput;
				if (userInput >= 1 && userInput <= numItems)
				{
					player.equipWeapon(player.inventory.get<Weapon>(userInput - 1));
				}
			}
		}
		std::cout << "----------------\n";*/
		break;
	}
	// Wyswietlenie statystyk
	case 3:
		std::cout << "Bohater\n=========\n";
		std::cout << player.name;
		if (player.className != "") std::cout << " the " << player.className;
		std::cout << std::endl;

		std::cout << "Zdrowie:   " << player.hp << " / " << player.maxHp << std::endl;
		std::cout << "Sila: " << player.strength << std::endl;
		std::cout << "Zrecznosc:  " << player.agility << std::endl;
		std::cout << "Poziom:    " << player.level << " (" << player.xp;
		std::cout << " / " << player.xpToLevel(player.level + 1) << ")" << std::endl;
		std::cout << "----------------\n";
		break;
	default:
		break;
	}
	return;
}

