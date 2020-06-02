#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <vector>

class Creature;

// możliwe działania
enum class BattleEventType { ATTACK, ATTACK_FAST, ATTACK_STRONG, DEFEND, FOCUS, DEFEND_ENEMY, FOCUS_ENEMY };

class BattleEvent
{
	public:

	Creature* source;
	Creature* target;
	
	BattleEventType type;
	
	BattleEvent(Creature* source, Creature* target, BattleEventType type);

	// rodzaj działania na funkcję
	int run();
};

class Battle
{
	private:

	// Uczestnicy gracz z id="player" i przeciwni-k/cy
	std::vector<Creature*> combatants;

	// usunięcie pokonanych
	void kill(Creature* creature);

	// Następna tura
	void nextTurn();

	public:

	// Konstruktor
	Battle(std::vector<Creature*>& combatants);

	// Walcz aż zostanie jeden
	void run();
};

#endif /* BATTLE_HPP */
