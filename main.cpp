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
#include "entity.hpp"
#include "player.hpp"
#include "battle.hpp"

// menu startowe
Player startGame();

// wyswietla przedmioty, statystyki
void dialogueMenu(Player& player);
int main()
{
	std::srand(std::time(nullptr));

    unsigned int rounds=0;
	Player player = startGame();
	player.hp=20;

	// gra trwa do zerwania petli
	while(1)
	{
            if(rounds==10){
                std::cout<<"Gratulacje! Wygrales";
                return 0;
            }

            std::vector<Creature*> combatants;
            combatants.push_back(&player);
			Battle battle(combatants);
			battle.run();

			// jesli gracz przezyl otrzymuje doswiadczenie
			if(player.hp > 0)
			{
			    rounds++;
			    dialogueMenu(player);
                system("cls");
				unsigned int xp = 0;
				std::cout << "Zdobyles " << xp << " doswiadczenia!\n";
				player.xp += xp;
				player.hp--;
				// restart petli
				continue;
			}
			// jesli gracz ma 0 hp gra sie konczy
			else
			{
				std::cout << "\t----UMARLES----\n    Koniec gry\n";
				return 0;
			}
		}

	return 0;
}

// tworzenie postaci lub wczytanie
Player startGame()
{
    std::cout <<"Witaj w grze! \nWalczysz na arenie, nie masz mozliwosci leczenia, czeka Cie 10 walk jezeli przezyjesz zwyciezysz! \n";
	std::cout << "Jakie imie chcesz wybrac?" << std::endl;
	std::string name;
	std::cin >> name;
    int result;
    std::cout << "Jaka klase postaci chcesz wybrac? \n 1-wojownik \n 2-bandyta" << std::endl;
    std::cin >> result;
	std::ifstream f((name).c_str());
	if(f.good())
	{
		f.close();

		// Return the player
	}
	/*
	else
	{
		f.close();


		switch(result)
		{
			 //Wojownik skupia sie na sile
			case 1:
				return Player(name, 15, 5, 4, 1, 0, 1);

			//Bandyta skupia sie na zrecznosci
			case 2:
				return Player(name, 15, 4, 5, 1, 0, 1);

			// case dla bezpieczenstwa
			default:
				return Player(name, 15, 4, 4, 1, 0, 1);
		}
	}
	*/
}

void dialogueMenu(Player& player)
{
	// menu
	int result;
	std::cout << "Wybierz opcje (1 - przedmioty 2 - statystyki przedmiotow 3 - statystyki postaci 4 - nastepna walka)";
    do{
	cin>>result;

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
			std::cout << "Ekwipunek\n=========\n";
			std::cout << "Zbroja: "
				<< std::endl;
			std::cout << "Bron: "
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
			std::cout << player.id;
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
    }while(result !=4);

	return;
}
