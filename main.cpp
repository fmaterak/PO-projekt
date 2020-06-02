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

#include "item.hpp"
#include "creature.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "battle.hpp"

// menu startowe
Player startGame();
Creature enemy(int room);

void dialogueMenu(Player& player);
// wyswietla przedmioty, statystyki
int main()
{
	std::srand(std::time(nullptr));

    unsigned int rounds=0;
	Player player = startGame();
	Creature wrog= Creature("enemy",10,5,3,3,10,10);
	

	// gra trwa do zerwania petli
	while(1)
	{
            if(rounds==10){
                std::cout<<"Gratulacje! Wygrales!\n";
                return 0;
            }
            std::vector<Creature*> combatants;
            combatants.push_back(&player);
            wrog= enemy(rounds);
            cout<<"  ^\n  |\n  | WALKA!\no-+-o\n  0\n";
            cout<<"Przeciwnik: "<<"hp-"<<wrog.hp<<" "<<"str-"<<wrog.strength<<" "<<"def-"<<wrog.defense<<" "<<"ag-"<<wrog.agility<<"\n";
            combatants.push_back(&wrog);
			Battle battle(combatants);
			battle.run();

			// jesli gracz przezyl otrzymuje doswiadczenie
			if(player.hp > 0)
			{
			    rounds++;
			    
                //system("cls");
                //std::cout<<"\n\n";
				std::cout << "Zdobyles " << wrog.xp << " doswiadczenia!\n";
				player.xp += wrog.xp;
				std::cout<< "Zdobyles " << wrog.gold << " zlota!\n";
				player.gold += wrog.gold;
				player.levelUp();
				//player.hp--;
				// restart petli
				dialogueMenu(player);
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
    std::cout <<"Witaj w grze! \nWalczysz na arenie, czeka Cie 10 walk, jezeli przezyjesz zwyciezysz! \n";
    
    int result;
    std::cout << "Jaka klase postaci chcesz wybrac? \n 1-wojownik \n 2-bandyta" << std::endl;
    std::cin >> result;
    
	switch(result)
		{
			 //Wojownik skupia sie na sile
			case 1:
				return Player("player", 15, 100, 4, 1, 0, 1, 0);

			//Bandyta skupia sie na zrecznosci
			case 2:
				return Player("player", 15, 50, 5, 1, 0, 1, 0);

			// case dla bezpieczenstwa
			default:
				return Player("player", 15, 4, 4, 1, 0, 1, 0);
	}
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
		{
			menu_ekwipunek(player.gold);
			break;//continue
		}
		case 2:
		{
			statystyki_przedmiotow();
			break;//continue
		}

		// jesli nie ma przedmiotow prosi o zalozenie
		
		case 3:
		{
			std::cout << "Bohater\n=========\n";
			std::cout << player.id;
			std::cout << std::endl;
			std::cout << "Zdrowie:    " << player.hp << " / " << player.maxHp << std::endl;
			std::cout << "Sila:       " << player.strength << std::endl;
			std::cout << "Obrona:     " << player.defense << std::endl;
			std::cout << "Zrecznosc:  " << player.agility << std::endl;
			std::cout << "Poziom:     " << player.level << " (" << player.xp;
			std::cout <<  " / " << player.xpToLevel(player.level+1) << ")" << std::endl;
			std::cout << "Zloto:      " << player.gold << std::endl;
			std::cout << "----------------\n";
			continue;
		}
		default:
			break;

	}
    }while(result !=4);

	return;
}

Creature enemy(int room)
{
 //room- przelicznik trudności/pomieszczenie
	int b=4; // <- zakres losowania (np. str 0-2)
	
	// Do dopracowania
	string id="enemy";
	int hp = rand() % b + (5*room+1);
	//int maxHp = this->hp;
	int strength = rand() % b + (room+1);
	int defense = rand() % b + (room+1);
	int agility = rand() % b + (room+1);
	unsigned int xp = hp + strength + defense + agility; // tu szczególnie
	unsigned int gold = rand() % b + room;
	return Creature(id,hp,strength,defense,agility,xp,gold);
}

