#include <iostream>
#include <string>
#include <fstream>
#include "Classes.h"
using namespace std;

GameManager::GameManager() : gameRunning(false), currentPlayer(nullptr), currentPlace(nullptr), historyCount(0), currentStage(1), currentSubPlaceIndex(0) {}

void GameManager::startGame(Player* player)
{
	currentPlayer = player;
	gameRunning = true;
	cout << "Game started with " << player->getName() << "!\n";
}

void GameManager::endGame()
{
	gameRunning = false;
	cout << "Game ended! ThankYou For Playing\n";
}

void GameManager::changePlace(Place* newPlace)
{
	currentPlace = newPlace;
	if (!currentPlace->getLocked())
		cout << "Moving to " << newPlace->getName() << endl;
	else
		cout << "Area is Locked!!\n";
}

void GameManager::battle(Enemy* enemy, Inventory* inventory, SubPlaces* subPlace)
{
	string message;
	cout << "Battle started against " << enemy->getName() << " in " << subPlace->getName() << "!\n";
	bool isBoss = subPlace->getBossInfo();
	int bossPhase;
	int maxPhases;
	if (isBoss)
	{
		bossPhase = 1;
		maxPhases = 2;
	}
	else
	{
		bossPhase = 0;
		maxPhases = 1;
	}

	while (!enemy->isDefeated() && currentPlayer->getHealth() > 0 && bossPhase <= maxPhases)
	{
		cout << "\nYour HP: " << currentPlayer->getHealth() << " | Enemy HP: " << enemy->getHealth() << "\n";
		if (isBoss)
			cout << "Boss Phase: " << bossPhase << "/" << maxPhases << "\n";
		cout << "1. Attack\n2. Use Item\n3. Defend\n4. Run\nChoose action: ";
		int choice;
		cin >> choice;

		message = currentPlayer->getName() + " vs " + enemy->getName() + ": ";
		if (choice == 1)
		{
			int damage = currentPlayer->getAttack() - enemy->getDefense();
			if (damage > 0)
			{
				enemy->takeDamage(damage);
				if (!isBoss)
					currentPlayer->takeDamage(enemy->getAttack() - currentPlayer->getDefence());
				else
					currentPlayer->takeDamage(enemy->getAttack() - currentPlayer->getDefence() / 10);

				message += "Player dealt " + to_string(damage) + " damage.";
			}
			else
			{
				message += "Player's attack was too weak!";
				//cout << message << endl;
			}
		}
		else if (choice == 2)
		{
			inventory->displayInventory();
			if (inventory->getItemCount() > 0)
				cout << "Select item (1-" << inventory->getItemCount() << "): ";
			else
			{
				cout << "No items in Inventory!\n";
				return;
			}
			int itemIndex;
			cin >> itemIndex;
			HelpingObject* item = inventory->getItem(itemIndex - 1);
			if (item)
			{
				currentPlayer->setHealth(currentPlayer->getHealth() + item->getRecovery());
				currentPlayer->setAttack(currentPlayer->getAttack() + item->getAttack());
				currentPlayer->setDefence(currentPlayer->getDefence() + item->getDefence());
				message += "Used item " + item->getName() + "!";
				inventory->removeItem(itemIndex - 1);
			}
			else
				message += "Invalid item selected.";
		}
		else if (choice == 3)
		{
			currentPlayer->setDefence(currentPlayer->getDefence() + 10);
			message += "Player defended, boosting defence by 10!";
			//cout << message << endl;
		}
		else
		{
			cout << "You Ran from the battle!\n";
			message += "Player Ran!";
			return;
		}

		if (!enemy->isDefeated())
		{
			int enemyDamage = enemy->getAttack() - currentPlayer->getDefence();
			if (enemyDamage > 0)
			{
				currentPlayer->takeDamage(enemyDamage);
				message += " Enemy dealt " + to_string(enemyDamage) + " damage.";
				//cout << message << endl;
			}
			else
			{
				message += " Enemy's attack was blocked!";
				//cout << message << endl;
			}
		}
		addBattleLog(message);

		// Teammate actions
		for (int i = 0; i < 3; i++)
		{
			Teammates* teammate = &(currentPlayer->getTeammates(i));
			if (teammate && !teammate->isDefeated())
			{
				int damage = teammate->getAttack() - enemy->getDefense();
				if (damage > 0)
				{
					enemy->takeDamage(damage);
					message += " " + teammate->getName() + " dealt " + to_string(damage) + " damage.";
					//cout << message << endl;
				}
				int enemyDamage = enemy->getAttack() - teammate->getDefence();
				if (enemyDamage > 0)
				{
					teammate->takeDamage(enemyDamage);
					message += " Enemy dealt " + to_string(enemyDamage) + " to " + teammate->getName() + ".";
					//cout << message << endl;
					if (teammate->isDefeated())
						cout << teammate->getName() << " is Defeted by " << enemy->getName() << "!!\n";
				}
			}
		}

		if (isBoss && enemy->getHealth() <= enemy->getHealth() / 2 && bossPhase < maxPhases)
		{
			bossPhase++;
			int recover = 0;
			switch (currentStage)
			{
			case 0:
				recover = 50;
				break;
			case 1:
				recover = 80;
				break;
			case 2:
				recover = 150;
				break;
			case 3:
				recover = 200;
				break;
			}
			enemy->setHealth(enemy->getHealth() + recover);
			cout << enemy->getName() << " enters phase " << bossPhase << "!\n";
			message += " Boss entered phase " + to_string(bossPhase) + ".";
		}

		addBattleLog(message);
	}

	if (enemy->isDefeated())
	{
		cout << enemy->getName() << " defeated!\n";
		currentPlayer->setExp(currentPlayer->getExp() + enemy->getExpLost());
		int recover = 0;
		switch (currentStage)
		{
		case 0:
			if (isBoss)
				recover = 50;
			else
				recover = 20;
			break;
		case 1:
			if (isBoss)
				recover = 80;
			else
				recover = 20;
			break;
		case 2:
			if (isBoss)
				recover = 100;
			else
				recover = 30;
			break;
		case 3:
			if (isBoss)
				recover = 100;
			else
				recover = 40;
			break;
		}
		currentPlayer->setHealth(currentPlayer->getHealth() + recover);
		cout << currentPlayer->getName() << "'s hp +" << recover << endl;
		if (isBoss)
		{
			currentPlayer->setPoints(currentPlayer->getPoints() + 150);
			cout << "+150 points\n";
		}
		else
		{
			currentPlayer->setPoints(currentPlayer->getPoints() + 50);
			cout << "+50 points\n";
		}
		addBattleLog(currentPlayer->getName() + " defeated " + enemy->getName() + "!");
		subPlace->removeEnemy(*enemy);
	}
	else if (currentPlayer->getHealth() <= 0)
	{
		cout << "You were defeated!\n";
		gameRunning = false;
	}
	cout << message << endl;
}

bool GameManager::isGameRunning() const
{
	return gameRunning;
}

void GameManager::saveGame(const Inventory* inventory, const string& filename)
{
	ofstream save(filename);
	if (!save)
	{
		cout << "Error saving game!\n";
		return;
	}

	save << currentPlayer->getName() << endl;
	save << currentPlayer->getHealth() << endl;
	save << currentPlayer->getAttack() << endl;
	save << currentPlayer->getDefence() << endl;
	save << currentPlayer->getPoints() << endl;
	save << currentPlayer->getExp() << endl;
	save << currentPlayer->getLevel() << endl;

	save << currentStage << endl;
	save << currentSubPlaceIndex << endl;

	save << inventory->getItemCount() << endl;
	for (int i = 0; i < inventory->getItemCount(); i++)
	{
		HelpingObject* item = inventory->getItem(i);
		save << item->getName() << endl;
		save << item->getPrice() << endl;
		save << item->getAttack() << endl;
		save << item->getDefence() << endl;
		save << item->getRecovery() << endl;
	}

	save << currentPlayer->getPlayerCount() << endl;;
	for (int i = 0; i < currentPlayer->teammateCount; i++)
	{
		Teammates* teammate = &(currentPlayer->getTeammates(i));
		save << teammate->getName() << endl;
		save << teammate->getAttack() << endl;
		save << teammate->getDefence() << endl;
		save << teammate->getHealth() << endl;
		save << teammate->getPrice() << endl;
	}

	save.close();
	cout << "Game saved successfully!\n";
}

void GameManager::loadGame(Player*& player, Inventory* inventory, string& filename)
{
	ifstream load(filename);
	if (!load)
	{
		cout << "Error loading game!\n";
		return;
	}

	string name;
	int health, attack, defence, points, exp, level, itemCount, teammateCount;

	getline(load, name);
	load >> health >> attack >> defence >> points >> exp >> level;
	load.ignore();

	load >> currentStage;
	load.ignore();
	load >> currentSubPlaceIndex;
	load.ignore();

	if (name == "Gojo")
		player = new Gojo(name, attack, health, defence, points);
	else if (name == "Tanjiro")
		player = new Tanjiro(name, attack, health, defence, points);
	else if (name == "Yuta")
		player = new Yuta(name, attack, health, defence, points);
	else
		player = new Zenitsu(name, attack, health, defence, points);

	player->setExp(exp);
	player->setLevel(level);

	load >> itemCount;
	load.ignore();
	for (int i = 0; i < itemCount; i++)
	{
		string itemName;
		int price, atk, def, rec;
		getline(load, itemName);
		load >> price >> atk >> def >> rec;
		load.ignore();

		HelpingObject* item = nullptr;

		// Wild Forest Items
		if (itemName == "Crossbow")
			item = new ObjectsForWild(HlpObjects::CROSSBOW, atk, def, price, rec);
		else if (itemName == "Dagger")
			item = new ObjectsForWild(HlpObjects::DAGGER, atk, def, price, rec);
		else if (itemName == "First Aid Kit")
			item = new ObjectsForWild(HlpObjects::FIRST_AID, atk, def, price, rec);
		else if (itemName == "Shield")
			item = new ObjectsForWild(HlpObjects::SHIELD, atk, def, price, rec);
		else if (itemName == "ShotGun")
			item = new ObjectsForWild(HlpObjects::GUN, atk, def, price, rec);

		// Demon Items
		else if (itemName == "Sun Breathing Techinque")
			item = new ObjectsForDemons(HlpObjects::SUN_BREATHING, atk, def, price, rec);
		else if (itemName == "Thunder Breathing Techinque")
			item = new ObjectsForDemons(HlpObjects::THUNDER_BREATHING, atk, def, price, rec);
		else if (itemName == "Demon Slayer Techinque")
			item = new ObjectsForDemons(HlpObjects::SWORD, atk, def, price, rec);
		else if (itemName == "Healing Breathing Techinque")
			item = new ObjectsForDemons(HlpObjects::HEAL_BREATHING, atk, def, price, rec);
		else if (itemName == "Wind Breathing Techinque")
			item = new ObjectsForDemons(HlpObjects::WIND_BREATHING, atk, def, price, rec);

		// Curse Items
		else if (itemName == "Curse Speech Amplifier")
			item = new ObjectsForCurses(HlpObjects::CURSE_SPEACH, atk, def, price, rec);
		else if (itemName == "Magic Spell")
			item = new ObjectsForCurses(HlpObjects::MAGIC_SPELL, atk, def, price, rec);
		else if (itemName == "Healing Spell")
			item = new ObjectsForCurses(HlpObjects::HEALING_SPELL, atk, def, price, rec);
		else if (itemName == "Killing Spell")
			item = new ObjectsForCurses(HlpObjects::KILLING_SPELL, atk, def, price, rec);
		else if (itemName == "Invisibility Spell")
			item = new ObjectsForCurses(HlpObjects::INVISIBLE_SPELL, atk, def, price, rec);

		// Jujutsu Items
		else if (itemName == "Limitless Technique")
			item = new ObjectsForJujutsu(HlpObjects::LIMITLESS_TECHNIQUE, atk, def, price, rec);
		else if (itemName == "Reverse Curse Technique")
			item = new ObjectsForJujutsu(HlpObjects::REVERSE_CURSE_TECHNIQUE, atk, def, price, rec);
		else if (itemName == "Six Eyes Technique")
			item = new ObjectsForJujutsu(HlpObjects::SIX_EYES, atk, def, price, rec);
		else if (itemName == "Special Grade Sword")
			item = new ObjectsForJujutsu(HlpObjects::SPECIAL_GRADE_ITEM, atk, def, price, rec);
		else if (itemName == "Domain Expansion")
			item = new ObjectsForJujutsu(HlpObjects::DOMAIN_EXPANSION, atk, def, price, rec);

		if (item)
			inventory->addItem(item);
	}

	load >> teammateCount;
	load.ignore();
	for (int i = 0; i < teammateCount; i++)
	{
		string teammateName;
		int atk, def, hp, price;
		getline(load, teammateName);
		load >> atk >> def >> hp >> price;
		load.ignore();

		Teammates* teammate = new Teammates(teammateName, atk, def, hp, price);
		player->addTeammate(teammate);
	}

	load.close();
	currentPlayer = player;
	gameRunning = true;
	cout << "Game loaded successfully!\n";
}

void GameManager::setCurrentStage(int stage) { currentStage = stage; }
void GameManager::setSubPlaceIndex(int index) { currentSubPlaceIndex = index; }
int  GameManager::getCurrentStage() const { return currentStage; }
int  GameManager::getSubPlaceIndex() const { return currentSubPlaceIndex; }
void GameManager::addBattleLog(const string& message)
{
	if (historyCount < 100)
	{
		battleHistory[historyCount] = message;
		historyCount++;
	}
}

void GameManager::viewBattleHistory() const
{
	cout << "Battle History:\n";
	for (int i = 0; i < historyCount; i++)
		cout << i + 1 << ". " << battleHistory[i] << "\n";
}

void GameManager::finalScoreReport(const Inventory* inventory) const
{
	cout << "\nFinal Score Report\n";
	cout << "Player: " << currentPlayer->getName() << "\n";
	cout << "Level: " << currentPlayer->getLevel() << "\n";
	cout << "XP: " << currentPlayer->getExp() << "\n";
	cout << "Points: " << currentPlayer->getPoints() << "\n";
	cout << "Battles Fought: " << historyCount << "\n";
	cout << "Items Owned: " << inventory->getItemCount() << "\n";
}