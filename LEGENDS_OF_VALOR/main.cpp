#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include "Classes.h"
using namespace std;

enum CHEAT { EXTRA_POINTS, EXTRA_HP, UNLIMITED_HP, UNLIMITED_ATTACK, UNLIMITED_POINTS, NOTHING };
void displayMenu()
{
	cout << "\n\n";
	cout << "\t\t\t\t\t|-----------------------------|\n";
	cout << "\t\t\t\t\t|     Legends of Valor        |\n";
	cout << "\t\t\t\t\t|-----------------------------|\n";
	cout << "\t\t\t\t\t|                             |\n";
	cout << "\t\t\t\t\t|  1. Explore                 |\n";
	cout << "\t\t\t\t\t|  2. View Stats              |\n";
	cout << "\t\t\t\t\t|  3. View Inventory          |\n";
	cout << "\t\t\t\t\t|  4. Visit Shop              |\n";
	cout << "\t\t\t\t\t|  5. View Teammates          |\n";
	cout << "\t\t\t\t\t|  6. View Battle History     |\n";
	cout << "\t\t\t\t\t|  7. Save Game               |\n";
	cout << "\t\t\t\t\t|  8. Quit                    |\n";
	cout << "\t\t\t\t\t|  9. Choose Stage            |\n";
	cout << "\t\t\t\t\t|                             |\n";
	cout << "\t\t\t\t\t|-----------------------------|\n";
	cout << "\t\t\t\t\tChoice: ";
}
CHEAT cheatPlace()
{
	for (int i = 5; i < 8; i++)
		Beep(1000 - (i * 10), 1000 - (i * 10));
	system("cls");
	string cheat;
	cin >> cheat;
	if (cheat == "$$points")
		return  EXTRA_POINTS;
	else if (cheat == "$$aspirin")
		return EXTRA_HP;
	else if (cheat == "$$gomad")
		return UNLIMITED_ATTACK;
	else if (cheat == "$$cheat")
		return UNLIMITED_HP;
	else if (cheat == "$$millionaire")
		return UNLIMITED_POINTS;

	return NOTHING;
}

int main()
{
	try {
		srand(time(0));
		GameManager game;
		Inventory* inventory = new Inventory();
		Shop* shop = new Shop();
		Player* currentPlayer = nullptr;
		bool isNewGame = true;

		// Initialize shop
		shop->addItem(new ObjectsForWild(HlpObjects::CROSSBOW, 20, 10, 50, 0));
		shop->addItem(new ObjectsForWild(HlpObjects::DAGGER, 40, 20, 60, 0));
		shop->addItem(new ObjectsForWild(HlpObjects::GUN, 30, 10, 40, 0));
		shop->addItem(new ObjectsForWild(HlpObjects::SHIELD, 10, 50, 60, 0));
		shop->addItem(new ObjectsForWild(HlpObjects::FIRST_AID, 0, 0, 30, 50));

		shop->addItem(new ObjectsForDemons(HlpObjects::SUN_BREATHING, 100, 30, 100, 10));
		shop->addItem(new ObjectsForDemons(HlpObjects::HEAL_BREATHING, 0, 15, 70, 50));
		shop->addItem(new ObjectsForDemons(HlpObjects::THUNDER_BREATHING, 70, 15, 70, 10));
		shop->addItem(new ObjectsForDemons(HlpObjects::WIND_BREATHING, 40, 15, 70, 10));

		shop->addItem(new ObjectsForJujutsu(HlpObjects::LIMITLESS_TECHNIQUE, 20, 50, 100, 30));
		shop->addItem(new ObjectsForJujutsu(HlpObjects::REVERSE_CURSE_TECHNIQUE, 0, 40, 200, 90));
		shop->addItem(new ObjectsForJujutsu(HlpObjects::DOMAIN_EXPANSION, 70, 80, 250, 60));
		shop->addItem(new ObjectsForJujutsu(HlpObjects::SPECIAL_GRADE_ITEM, 60, 30, 100, 0));
		shop->addItem(new ObjectsForJujutsu(HlpObjects::SIX_EYES, 60, 50, 150, 20));

		shop->addItem(new ObjectsForCurses(HlpObjects::CURSE_SPEACH, 40, 20, 100, 5));
		shop->addItem(new ObjectsForCurses(HlpObjects::HEALING_SPELL, 0, 20, 100, 50));
		shop->addItem(new ObjectsForCurses(HlpObjects::INVISIBLE_SPELL, 0, 70, 130, 10));
		shop->addItem(new ObjectsForCurses(HlpObjects::KILLING_SPELL, 60, 20, 150, 10));

		shop->addTeammate(new Teammates("Giyu", 60, 40, 80, 200));
		shop->addTeammate(new Teammates("Itadori Yuji", 50, 30, 90, 150));
		shop->addTeammate(new Teammates("Toji Zenin", 70, 50, 90, 200));
		shop->addTeammate(new Teammates("Inoske", 40, 30, 90, 100));

		cout << "\t\t\t\t\t|-----------------------------|\n";
		cout << "\t\t\t\t\t|     Legends of Valor        |\n";
		cout << "\t\t\t\t\t|-----------------------------|\n\n\n\n";
		RoadMap::printMap();
		cout << "\n1. New Game\n2. Load Game\nChoice: ";
		int choice;
		if (cin >> choice)
		{
		}
		else
			throw 0;

			if (choice != 1 && choice != 2)
			{
				cout << "Invalid Choice!\nStarting New Game\n";
				choice = 1;
			}
			if (choice == 1)
			{
				cout << "Choose your character:\n1. Gojo\n2. Tanjiro\n3. Yuta\n4. Zenitsu\nChoice: ";
				if (cin >> choice)
				{
				}
				else
					throw 0;
				string name;
				cout << "Enter character name: ";
				if (cin >> name)
				{
				}
				else throw 0;

				switch (choice)
				{
				case 1:
					currentPlayer = new Gojo(name, 50, 100, 40, 100);
					break;
				case 2:
					currentPlayer = new Tanjiro(name, 30, 100, 20, 100);
					break;
				case 3:
					currentPlayer = new Yuta(name, 45, 100, 35, 100);
					break;
				case 4:
					currentPlayer = new Zenitsu(name, 30, 100, 20, 100);
					break;
				default:
					currentPlayer = new Gojo("Gojo", 50, 100, 40, 100);
				}
				game.startGame(currentPlayer);
			}
			else if (choice == 2)
			{
				string filename;
				cout << "Enter save file name: ";
				cin >> filename;
				game.loadGame(currentPlayer, inventory, filename);
				isNewGame = false;
			}

			WildForest* wildForest = new WildForest();
			CursedHouse* cursedHouse = new CursedHouse();
			DemonVillage* demonVillage = new DemonVillage();
			JujutsuWorld* jujutsuWorld = new JujutsuWorld();

			// Wild Forest SubPlaces
			WildForestSubPlaces* trees = new WildForestSubPlaces(Places::TREES, HlpObjects::CROSSBOW, 2, 1, 1);
			WildForestSubPlaces* rocks = new WildForestSubPlaces(Places::ROCKS, HlpObjects::SHIELD, 2, 1, 2);
			WildForestSubPlaces* river = new WildForestSubPlaces(Places::RIVER, HlpObjects::FIRST_AID, 3, 1, 3);
			WildForestSubPlaces* cave = new WildForestSubPlaces(Places::CAVE, HlpObjects::GUN, 1, 1, 4);
			cave->setBossInfo(true);
			wildForest->addConnectedPlace(*trees);
			wildForest->addConnectedPlace(*rocks);
			wildForest->addConnectedPlace(*river);
			wildForest->addConnectedPlace(*cave);

			// Cursed House SubPlaces
			CurseHouseSubPlaces* lobby = new CurseHouseSubPlaces(Places::LOBBY, HlpObjects::HEALING_SPELL, 2, 1, 5);
			CurseHouseSubPlaces* kitchen = new CurseHouseSubPlaces(Places::KITCHEN, HlpObjects::MAGIC_SPELL, 2, 1, 6);
			CurseHouseSubPlaces* rooftop = new CurseHouseSubPlaces(Places::ROOF_TOP, HlpObjects::KILLING_SPELL, 3, 1, 7);
			CurseHouseSubPlaces* sukuna = new CurseHouseSubPlaces(Places::SUKUNA_DOMAIN, HlpObjects::INVISIBLE_SPELL, 1, 1, 8);
			sukuna->setBossInfo(true);
			cursedHouse->addConnectedPlace(*lobby);
			cursedHouse->addConnectedPlace(*kitchen);
			cursedHouse->addConnectedPlace(*rooftop);
			cursedHouse->addConnectedPlace(*sukuna);

			// Demon Village SubPlaces
			DemonVillageSubPlaces* bridge = new DemonVillageSubPlaces(Places::BRIDGE, HlpObjects::SUN_BREATHING, 2, 1, 9);
			DemonVillageSubPlaces* brokenHouse = new DemonVillageSubPlaces(Places::BROKEN_HOUSE, HlpObjects::THUNDER_BREATHING, 2, 1, 10);
			DemonVillageSubPlaces* demonCastle = new DemonVillageSubPlaces(Places::DEMON_CASTLE, HlpObjects::SWORD, 3, 1, 11);
			DemonVillageSubPlaces* infinity = new DemonVillageSubPlaces(Places::INFINITY_CASTLE, HlpObjects::WIND_BREATHING, 1, 1, 12);
			infinity->setBossInfo(true);
			demonVillage->addConnectedPlace(*bridge);
			demonVillage->addConnectedPlace(*brokenHouse);
			demonVillage->addConnectedPlace(*demonCastle);
			demonVillage->addConnectedPlace(*infinity);

			// Jujutsu World SubPlaces
			JujutsuWorldSubPlaces* tengen = new JujutsuWorldSubPlaces(Places::TENGEN_PLACE, HlpObjects::SIX_EYES, 2, 1, 13);
			JujutsuWorldSubPlaces* jjkHigh = new JujutsuWorldSubPlaces(Places::JJK_HIGH, HlpObjects::REVERSE_CURSE_TECHNIQUE, 2, 1, 14);
			JujutsuWorldSubPlaces* shibuya = new JujutsuWorldSubPlaces(Places::SHIBUYA, HlpObjects::SPECIAL_GRADE_ITEM, 3, 1, 15);
			JujutsuWorldSubPlaces* gojoDomain = new JujutsuWorldSubPlaces(Places::GOJO_DOMAIN, HlpObjects::DOMAIN_EXPANSION, 1, 1, 16);
			gojoDomain->setBossInfo(true);
			jujutsuWorld->addConnectedPlace(*tengen);
			jujutsuWorld->addConnectedPlace(*jjkHigh);
			jujutsuWorld->addConnectedPlace(*shibuya);
			jujutsuWorld->addConnectedPlace(*gojoDomain);

			// Add enemies
			trees->addEnemy(*(new WildEnemy(Enemies::LION, 50, 20, 10, 50)));
			trees->addEnemy(*(new WildEnemy(Enemies::TIGER, 60, 25, 15, 60)));
			rocks->addEnemy(*(new WildEnemy(Enemies::SNAKE, 70, 30, 20, 70)));
			rocks->addEnemy(*(new WildEnemy(Enemies::LION, 50, 20, 10, 50)));
			river->addEnemy(*(new WildEnemy(Enemies::TIGER, 60, 25, 15, 60)));
			river->addEnemy(*(new WildEnemy(Enemies::SNAKE, 70, 30, 20, 70)));
			river->addEnemy(*(new WildEnemy(Enemies::LION, 50, 20, 10, 50)));
			cave->addEnemy(*(new WildEnemy(Enemies::BEAST, 100, 40, 30, 200)));
			lobby->addEnemy(*(new CurseEnemy(Enemies::CURSES, 80, 35, 25, 80)));
			lobby->addEnemy(*(new CurseEnemy(Enemies::VAMPIRE, 90, 40, 30, 90)));
			kitchen->addEnemy(*(new CurseEnemy(Enemies::BAD_SPIRIT, 100, 45, 35, 100)));
			kitchen->addEnemy(*(new CurseEnemy(Enemies::CURSES, 80, 35, 25, 80)));
			rooftop->addEnemy(*(new CurseEnemy(Enemies::VAMPIRE, 90, 40, 30, 90)));
			rooftop->addEnemy(*(new CurseEnemy(Enemies::BAD_SPIRIT, 100, 45, 35, 100)));
			rooftop->addEnemy(*(new CurseEnemy(Enemies::CURSES, 80, 35, 25, 80)));
			sukuna->addEnemy(*(new CurseEnemy(Enemies::KING_OF_CURSES, 250, 80, 50, 300)));
			bridge->addEnemy(*(new DemonEnemy(Enemies::UPPER_DEMONS, 110, 50, 40, 110)));
			bridge->addEnemy(*(new DemonEnemy(Enemies::LOWER_MOON, 120, 55, 45, 120)));
			brokenHouse->addEnemy(*(new DemonEnemy(Enemies::UPPER_MOON, 130, 60, 50, 130)));
			brokenHouse->addEnemy(*(new DemonEnemy(Enemies::UPPER_DEMONS, 110, 50, 40, 110)));
			demonCastle->addEnemy(*(new DemonEnemy(Enemies::LOWER_MOON, 120, 55, 45, 120)));
			demonCastle->addEnemy(*(new DemonEnemy(Enemies::UPPER_MOON, 130, 60, 50, 130)));
			demonCastle->addEnemy(*(new DemonEnemy(Enemies::UPPER_DEMONS, 110, 50, 40, 110)));
			infinity->addEnemy(*(new DemonEnemy(Enemies::DEMON_KING, 200, 80, 70, 400)));
			tengen->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_I, 140, 65, 55, 140)));
			tengen->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_II, 150, 70, 60, 150)));
			jjkHigh->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_III, 160, 75, 65, 160)));
			jjkHigh->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_I, 140, 65, 55, 140)));
			shibuya->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_II, 150, 70, 60, 150)));
			shibuya->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_III, 160, 75, 65, 160)));
			shibuya->addEnemy(*(new JujutsuEnemy(Enemies::GRADE_I, 140, 65, 55, 140)));
			gojoDomain->addEnemy(*(new JujutsuEnemy(Enemies::SPECIAL_GRADE, 400, 150, 150, 500)));

			// Add items
			trees->addHelpingObj(*(new ObjectsForWild(HlpObjects::CROSSBOW, 20, 10, 50, 0)));
			rocks->addHelpingObj(*(new ObjectsForWild(HlpObjects::SHIELD, 0, 20, 40, 0)));
			river->addHelpingObj(*(new ObjectsForWild(HlpObjects::FIRST_AID, 0, 0, 30, 50)));
			cave->addHelpingObj(*(new ObjectsForWild(HlpObjects::GUN, 30, 0, 60, 0)));
			lobby->addHelpingObj(*(new ObjectsForCurses(HlpObjects::HEALING_SPELL, 0, 0, 50, 60)));
			kitchen->addHelpingObj(*(new ObjectsForCurses(HlpObjects::MAGIC_SPELL, 25, 15, 70, 0)));
			rooftop->addHelpingObj(*(new ObjectsForCurses(HlpObjects::KILLING_SPELL, 35, 0, 80, 0)));
			sukuna->addHelpingObj(*(new ObjectsForCurses(HlpObjects::INVISIBLE_SPELL, 0, 30, 90, 0)));
			bridge->addHelpingObj(*(new ObjectsForDemons(HlpObjects::SUN_BREATHING, 30, 15, 70, 0)));
			brokenHouse->addHelpingObj(*(new ObjectsForDemons(HlpObjects::THUNDER_BREATHING, 25, 10, 60, 0)));
			demonCastle->addHelpingObj(*(new ObjectsForDemons(HlpObjects::SWORD, 35, 0, 80, 0)));
			infinity->addHelpingObj(*(new ObjectsForDemons(HlpObjects::WIND_BREATHING, 0, 25, 90, 0)));
			tengen->addHelpingObj(*(new ObjectsForJujutsu(HlpObjects::SIX_EYES, 40, 20, 100, 0)));
			jjkHigh->addHelpingObj(*(new ObjectsForJujutsu(HlpObjects::REVERSE_CURSE_TECHNIQUE, 0, 0, 80, 70)));
			shibuya->addHelpingObj(*(new ObjectsForJujutsu(HlpObjects::SPECIAL_GRADE_ITEM, 45, 25, 110, 0)));
			gojoDomain->addHelpingObj(*(new ObjectsForJujutsu(HlpObjects::DOMAIN_EXPANSION, 50, 30, 120, 0)));

			jujutsuWorld->calculateTotal();
			demonVillage->calculateTotal();
			wildForest->calculateTotal();
			cursedHouse->calculateTotal();

			Place* stages[4] = { wildForest, cursedHouse, demonVillage, jujutsuWorld };
			int currentStage = 0;
			ManageStats stats(currentPlayer);
			stages[currentStage]->setLocked(false);

			if (!isNewGame)
			{
				currentStage = game.getCurrentStage();
			}
			while (game.isGameRunning() && currentStage < 4)
			{
				cout << "\n\n";
				cout << "\t\t\t\t\t|-----------------------------|\n";
				cout << "\t\t\t\t\t|       Legends of Valor      |\n";
				cout << "\t\t\t\t\t|-----------------------------|\n\n\n\n";
				for (int i = 0; i < 4; i++)
				{
					cout << i + 1 << ". " << stages[i]->getName();
					if (stages[i]->getLocked())
						cout << " (Locked)";
					cout << endl;
				}
				cout << "Enter Your Choice: " << endl;
				int choose;
				if (cin >> choose) {}
				else throw 0;
				switch (choose)
				{
				case 1:
					currentStage = 0;
					break;
				case 2:
					currentStage = 1;
					break;
				case 3:
					currentStage = 2;
					break;
				case 4:
					currentStage = 3;
					break;
				default:
					currentStage = 0;
					cout << "Invalid Choice! Place set to " << stages[0]->getName() << endl;
				}

				game.changePlace(stages[currentStage]);
				SubPlaces* subPlaces[4];
				if (currentStage == 0)
				{
					subPlaces[0] = trees;
					subPlaces[1] = rocks;
					subPlaces[2] = river;
					subPlaces[3] = cave;
				}
				else if (currentStage == 1)
				{
					subPlaces[0] = lobby;
					subPlaces[1] = kitchen;
					subPlaces[2] = rooftop;
					subPlaces[3] = sukuna;
				}
				else if (currentStage == 2)
				{
					subPlaces[0] = bridge;
					subPlaces[1] = brokenHouse;
					subPlaces[2] = demonCastle;
					subPlaces[3] = infinity;
				}
				else
				{
					subPlaces[0] = tengen;
					subPlaces[1] = jjkHigh;
					subPlaces[2] = shibuya;
					subPlaces[3] = gojoDomain;
				}

				bool brk = false;
				bool chk = false;
				int startSubPlace = 0;
				if (!isNewGame)
				{
					startSubPlace = game.getSubPlaceIndex();
				}
				for (int i = startSubPlace; i < 4 && game.isGameRunning() && !brk; i++)
				{
					_getch();
					system("cls");
					SubPlaces* currentSubPlace = subPlaces[i];
					if (currentPlayer->getLevel() < currentSubPlace->getLevelThreshold())
					{
						cout << "Level " << currentSubPlace->getLevelThreshold() << " required to enter " << currentSubPlace->getName() << "!\n";
						chk = true;
						break;
					}

					cout << "\nEntering " << currentSubPlace->getName() << " ( Level: " << currentSubPlace->getLevelThreshold() << ")\n";
					stages[currentStage]->setLocked(false);
					displayMenu();
					if (cin >> choice) {}
					else throw 0;

					while (choice != 1 && game.isGameRunning() && !brk)
					{
						brk = false;
						system("cls");
						if (choice == 2)
						{
							cout << "\nStats:\nName: " << currentPlayer->getName() << "\nLevel: " << currentPlayer->getLevel()
								<< "\nHP: " << currentPlayer->getHealth() << "\nAttack: " << currentPlayer->getAttack()
								<< "\nDefence: " << currentPlayer->getDefence() << "\nPoints: " << currentPlayer->getPoints()
								<< "\nExp: " << currentPlayer->getExp() << "\n";
						}
						else if (choice == 3)
						{
							inventory->displayInventory();
						}
						else if (choice == 4)
						{
							cout << "Available Points: " << currentPlayer->getPoints() << endl;
							shop->displayShop();
							cout << "\nPlayer Menu:\n";
							cout << "1. Buy Item\n2. Recruit Teammate\n3. Back\nChoice: ";
							int shopChoice;
							if (cin >> shopChoice) {}
							else throw 0;
							if (shopChoice == 0)
							{
								CHEAT cheat = cheatPlace();
								switch (cheat)
								{
								case EXTRA_POINTS:
									currentPlayer->setPoints(currentPlayer->getPoints() + 100);
									Beep(500, 500);
									cout << "Cheat Code Activated!! +100 Points\n";
									break;
								case EXTRA_HP:
									currentPlayer->setHealth(currentPlayer->getHealth() + 50);
									Beep(500, 500);
									cout << "Cheat Code Activated!! +50 Hp\n";
									break;
								case UNLIMITED_ATTACK:
									currentPlayer->setAttack(99999999);
									cout << "Cheat Code Activated!! Unlimited Attack\n";
									Beep(500, 500);
									break;
								case UNLIMITED_HP:
									currentPlayer->setHealth(99999999);
									cout << "Cheat Code Activated!! Unlimited Health\n";
									Beep(500, 500);
									break;
								case UNLIMITED_POINTS:
									currentPlayer->setPoints(99999999);
									cout << "Cheat Code Activated!! Unlimited Points\n";
									Beep(500, 500);
									break;
								default:
									cout << "Penalty!!\n";
									Beep(500, 500);
									currentPlayer->setPoints(currentPlayer->getPoints() - 50);
									currentPlayer->setHealth(currentPlayer->getHealth() - 30);
									currentPlayer->setAttack(currentPlayer->getAttack() - 30);
									cout << "30- Attack\n30- Hp\n50- Points\n";
									_getch();
									system("cls");
								}
							}
							if (shopChoice == 1)
							{
								cout << "Enter item number: ";
								int itemIndex;
								if (cin >> itemIndex) {}
								else throw 0;
								HelpingObject* item = shop->buyItem(itemIndex, currentPlayer);
								if (item)
									inventory->addItem(item);
							}
							else if (shopChoice == 2)
							{
								cout << "Enter teammate number: ";
								int teammateIndex;
								cin >> teammateIndex;
								Teammates* teammate = shop->buyTeammate(teammateIndex, currentPlayer);
								if (teammate)
									currentPlayer->addTeammate(teammate);
							}
						}
						else if (choice == 5)
						{
							currentPlayer->displayTeammates();
						}
						else if (choice == 6)
						{
							game.viewBattleHistory();
						}
						else if (choice == 7)
						{
							string filename;
							cout << "Enter save file name: ";
							cin >> filename;
							game.setCurrentStage(currentStage);
							game.setSubPlaceIndex(i);
							game.saveGame(inventory, filename);
						}
						else if (choice == 8)
						{
							game.endGame();
							break;
						}
						else if (choice == 9)
						{
							brk = true;
							break;
						}
						_getch();
						system("cls");
						displayMenu();
						if (cin >> choice) {}
						else throw 0;
					}

					if (choice == 1)
					{
						char opt;
						if (currentSubPlace->getNoOfEnemies() > 0 && game.isGameRunning())
						{
							do {
								Enemy* enemy = currentSubPlace->getEnemy();
								game.battle(enemy, inventory, currentSubPlace);
								if (currentPlayer->getExp() >= currentPlayer->getLevel() * 100)
									stats.levelUp();
								cout << "Enter 0 to return to Game Options or Press any Key to Continue Game\n";
								opt = _getch();
							} while (currentSubPlace->getNoOfEnemies() > 0 && game.isGameRunning() && opt != '0');
							if (opt == '0')
								i--;
						}

						if (currentSubPlace->getNoOfObjects() > 0)
						{
							HelpingObject* item = currentSubPlace->getHelpingObj();
							cout << "Found " << item->getName() << "!\n";
							inventory->addItem(item);
							currentSubPlace->removeHelpingObj(*item);
						}

						if (currentSubPlace->getBossInfo() && currentSubPlace->getNoOfEnemies() == 0)
						{
							currentPlayer->victoryDialogue();
							cout << stages[currentStage]->getName() << " cleared!\n";
							if (currentStage != 4)
								stages[currentStage + 1]->setLocked(false);
							game.setSubPlaceIndex(3);
						}
					}
				}

				if (game.isGameRunning() && !chk)
				{
					game.setSubPlaceIndex(0);
				}
			}

			if (game.isGameRunning())
			{
				cout << "Congratulations! You completed Legends of Valor!\n";
				currentPlayer->victoryDialogue();
			}
			game.finalScoreReport(inventory);

			delete currentPlayer;
			delete inventory;
			delete shop;
			delete trees;
			delete rocks;
			delete river;
			delete cave;
			delete lobby;
			delete kitchen;
			delete rooftop;
			delete sukuna;
			delete bridge;
			delete brokenHouse;
			delete demonCastle;
			delete infinity;
			delete tengen;
			delete jjkHigh;
			delete shibuya;
			delete gojoDomain;
			delete wildForest;
			delete cursedHouse;
			delete demonVillage;
			delete jujutsuWorld;
		}
	
	catch (...)
	{
		cout << "Exception occured!!\nInvalid Input!!\nExiting Game...\n";
	}

	return 0;
}