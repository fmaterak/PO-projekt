#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include "battle.hpp"
#include "creature.hpp"

BattleEvent::BattleEvent(Creature* source, Creature* target, BattleEventType type)
{
	this->source = source;
	this->target = target;
	this->type = type;
}

int BattleEvent::run()
{
	switch(type)
	{
		case BattleEventType::ATTACK:
			return source->attack(target);
		case BattleEventType::ATTACK_FAST:
			return source->attack_fast(target);
		case BattleEventType::ATTACK_STRONG:
			return source->attack(target);
		case BattleEventType::DEFEND:
			return source->defend();
		case BattleEventType::FOCUS:
			return source->focus();
		case BattleEventType::DEFEND_ENEMY:
			return source->defend_enemy(target);
		case BattleEventType::FOCUS_ENEMY:
			return source->focus_enemy(target);
		default:
			return 0;
	}
}

void Battle::kill(Creature* creature)
{
	// Znajdz pozycje Creature w vectorze
	auto pos = std::find(this->combatants.begin(), this->combatants.end(), creature);

	// Nie proboj jezeli nie istnieje
	if(pos != this->combatants.end())
	{
		std::cout << creature->id << " zostal pokonany!\n"; // uwaga, zmiana id moze zmienic kolejnosc działań

		// Upewnienie sie ze nie zyje :)
		creature->hp = 0;
		// Remove the creature
		this->combatants.erase(pos);
	}

	return;
}
	//przydzielanie unikalnego id dla kilku przeciwników?

void Battle::run()
{
	std::vector<Creature*>::iterator player;
	std::vector<Creature*>::iterator end;

	do
	{
		// walcz, aż zostanie jeden
		player = std::find_if(this->combatants.begin(), this->combatants.end(),
			[](Creature* a) { return a->id == "player"; });
		end = this->combatants.end();

		this->nextTurn();
	}
	while(player != end && this->combatants.size() > 1);

	return;
}
Battle::Battle(std::vector<Creature*>& combatants)
{
}


void Battle::nextTurn()
{
	// kolejka, gracz pierwszy ("player">"enemy")
	std::queue<BattleEvent> events;
	std::sort(combatants.begin(), combatants.end(), [](Creature* a, Creature* b) { return a->id > b->id; });//jak gracz to na początek
	// przelatywanie po uczestnikach walki
	for(auto com : this->combatants)
	{
		// baardzo proste ai przciwnika
		int enemy_action = rand() % 5 + 1;
		switch(enemy_action)
		{
			case 1:
			{
				std::cout<<"Przeciwnik szykuje unik!\n";
				break;
			}
			case 2:
			{
				std::cout<<"Przeciwnik sie broni!\n";
				break;
			}
			default:
			{
				std::cout<<"Przeciwnik zaatakuje!\n";
				break;
			}
		}

		if(com->id == "player")
		{
			// tu by byl wybor przeciwnika

			// zapytaj o akcje
			std::cout<<"Co chcesz zrobic?\n1. Atak\n2. Szybki atak\n3. Silny atak\n4. Obrona\n5. Skupienie (na uniku)\n";
			int choice;
			std::cin>>choice;
			//takie male obejscie dla obrony i uniku przeciwnika
			if (enemy_action == 1)
			{
				int position = 1;
					for(int i = 0; i < position; ++i)
					{
						if(this->combatants[i]->id == "player") ++position;
					}
					Creature* target = this->combatants[position-1];
					events.push(BattleEvent(com, target, BattleEventType::DEFEND_ENEMY));
			}
			if (enemy_action == 2)
			{
				int position = 1;
					for(int i = 0; i < position; ++i)
					{
						if(this->combatants[i]->id == "player") ++position;
					}
					Creature* target = this->combatants[position-1];
					events.push(BattleEvent(com, target, BattleEventType::FOCUS_ENEMY));
			}

			switch(choice)
			{
				default:
				case 1:
				{
					// dla kilku przeciwników bylby tutaj wybor
					
					// dla 1 przeciwnika nie ma wyboru :v
					int position = 1;
					for(int i = 0; i < position; ++i)
					{
						if(this->combatants[i]->id == "player") ++position;
					}
					Creature* target = this->combatants[position-1];
					// dodaj do kolejki
					events.push(BattleEvent(com, target, BattleEventType::ATTACK));
					break;
				}
				case 2:
				{
					int position = 1;
					for(int i = 0; i < position; ++i)
					{
						if(this->combatants[i]->id == "player") ++position;
					}
					Creature* target = this->combatants[position-1];
					
					events.push(BattleEvent(com, target, BattleEventType::ATTACK_FAST));
					break;
				}
				case 3:
				{
					int position = 1;
					for(int i = 0; i < position; ++i)
					{
						if(this->combatants[i]->id == "player") ++position;
					}
					Creature* target = this->combatants[position-1];
					
					events.push(BattleEvent(com, target, BattleEventType::ATTACK_STRONG));
					break;
				}
				case 4:
				{
					// obrona
					events.push(BattleEvent(com, nullptr, BattleEventType::DEFEND));
					break;
				}
				case 5:
				{
					// skupienie sie na uniku
					events.push(BattleEvent(com,nullptr, BattleEventType::FOCUS));
					break;
				}
			}
		}
		else
		{
			if (enemy_action != 1 || enemy_action != 2)
			{
				// atak przciwnika
				Creature* player = *std::find_if(this->combatants.begin(), this->combatants.end(),
					[](Creature* a) { return a->id == "player"; });
				events.push(BattleEvent(com, player, BattleEventType::ATTACK));
			}
		}
	}

	// doprowadz do eventow
	while(!events.empty())
	{
		// bierz po kolei
		BattleEvent event = events.front();
		switch(event.type)
		{
			case BattleEventType::ATTACK:
			{
				// sprawdzenie czy uczestnicy moga wykonac dzialanie (czy zyja)
				auto a = this->combatants.begin();
				auto b = this->combatants.end();
				if(std::find(a, b, event.source) == b || std::find(a, b, event.target) == b)
				{
					break;
				}
				
				std::cout << event.source->id
					<< " bije "
					<< event.target->id
					<< " za "
					<< event.run()
					<< " obrazen!\n";
				// zabij jesli nie zyje
				if(event.target->hp <= 0)
				{
					this->kill(event.target);
				}
				break;
			}
			case BattleEventType::ATTACK_FAST:
			{
				auto a = this->combatants.begin();
				auto b = this->combatants.end();
				if(std::find(a, b, event.source) == b || std::find(a, b, event.target) == b)
				{
					break;
				}
				std::cout << event.source->id
					<< " bije "
					<< event.target->id
					<< " za "
					<< event.run()
					<< " obrazen!\n";
				
				if(event.target->hp <= 0)
				{
					this->kill(event.target);
				}
				break;
			}
			case BattleEventType::ATTACK_STRONG:
			{
				auto a = this->combatants.begin();
				auto b = this->combatants.end();
				if(std::find(a, b, event.source) == b || std::find(a, b, event.target) == b)
				{
					break;
				}
				std::cout << event.source->id
					<< " bije "
					<< event.target->id
					<< " za "
					<< event.run()
					<< " obrazen!\n";
				if(event.target->hp <= 0)
				{
					this->kill(event.target);
				}
				break;
			}
			case BattleEventType::DEFEND:
			{
				std::cout << "Obrona rosnie!\n";
				std::cout << event.source->defense
					<<" -> "
					<< event.run()
					<< "!\n";
				break;
			}
			case BattleEventType::FOCUS:
			{
				std::cout << "Zrecznosc rosnie!\n";
				std::cout << event.source->agility
					<<" -> "
					<< event.run()
					<< "!\n";
				break;
			}
			case BattleEventType::DEFEND_ENEMY:
			{
				std::cout << "Obrona przeciwnika rosnie!\n";
				std::cout << event.target->defense
					<<" -> "
					<< event.run()
					<< "!\n";
				break;
			}
			case BattleEventType::FOCUS_ENEMY:
			{
				std::cout << "Zrecznosc przeciwnika rosnie!\n";
				std::cout << event.target->agility
					<<" -> "
					<< event.run()
					<< "!\n";
				break;
			}
			default:
				break;
		}
		events.pop();
	}
}
