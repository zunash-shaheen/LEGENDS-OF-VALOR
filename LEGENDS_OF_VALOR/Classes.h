#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Forward Declarations
class Places;
class SubPlaces;
class Player;
class Inventory;
class Enemy;
class HlpObjects;
class Shop;
class Teammates;
class ManageStats;
class GameManager;

// Enums
struct Places
{
	enum WILD_FOREST { RIVER, ROCKS, CAVE, TREES };
	enum CURSED_HOUSE { LOBBY, KITCHEN, ROOF_TOP, SUKUNA_DOMAIN };
	enum DEMON_VILLAGE { BRIDGE, BROKEN_HOUSE, DEMON_CASTLE, INFINITY_CASTLE };
	enum JUJUTSU_WORLD { TENGEN_PLACE, JJK_HIGH, SHIBUYA, GOJO_DOMAIN };
};
struct Enemies
{
	enum WILD { LION, TIGER, SNAKE, BEAST };
	enum CURSE { CURSES, VAMPIRE, BAD_SPIRIT, KING_OF_CURSES };
	enum DEMON { UPPER_DEMONS, LOWER_MOON, UPPER_MOON, DEMON_KING };
	enum JUJUTSU { GRADE_I, GRADE_II, GRADE_III, SPECIAL_GRADE };
};
struct HlpObjects
{
	enum FOR_WILD { CROSSBOW, DAGGER, FIRST_AID, SHIELD, GUN };
	enum FOR_CURSES { CURSE_SPEACH, MAGIC_SPELL, HEALING_SPELL, KILLING_SPELL, INVISIBLE_SPELL };
	enum FOR_DEMONS { SUN_BREATHING, THUNDER_BREATHING, SWORD, HEAL_BREATHING, WIND_BREATHING };
	enum FOR_JUJUTSU { LIMITLESS_TECHNIQUE, REVERSE_CURSE_TECHNIQUE, SIX_EYES, SPECIAL_GRADE_ITEM, DOMAIN_EXPANSION };
};

// Classes Definition

// Helping Objects
class HelpingObject
{
protected:
	string name;
	int price;
public:
	virtual string getName() = 0;
	virtual int getPrice() = 0;
	virtual int getAttack() { return 0; }
	virtual int getDefence() { return 0; }
	virtual int getRecovery() { return 0; }
};

class Weapon : virtual public HelpingObject
{
protected:
	int attack;
	int defence;
public:
	virtual int getAttack() = 0;
	virtual int getDefence() = 0;
};

class Potion : virtual public HelpingObject
{
protected:
	int recovery;
public:
	virtual int getRecovery() = 0;
};

class ObjectsForWild : public Weapon, public Potion
{
	HlpObjects::FOR_WILD type;
public:
	ObjectsForWild(HlpObjects::FOR_WILD type, int atk, int def, int price, int recover);
	string getName();
	int getPrice();
	int getAttack();
	int getDefence();
	int getRecovery();
};

class ObjectsForDemons : public Weapon, public Potion
{
	HlpObjects::FOR_DEMONS type;
public:
	ObjectsForDemons(HlpObjects::FOR_DEMONS type, int atk, int def, int price, int recover);
	string getName();
	int getPrice();
	int getAttack();
	int getDefence();
	int getRecovery();
};

class ObjectsForCurses : public Weapon, public Potion
{
	HlpObjects::FOR_CURSES type;
public:
	ObjectsForCurses(HlpObjects::FOR_CURSES type, int atk, int def, int price, int recover);
	string getName();
	int getPrice();
	int getAttack();
	int getDefence();
	int getRecovery();
};

class ObjectsForJujutsu : public Weapon, public Potion
{
	HlpObjects::FOR_JUJUTSU type;
public:
	ObjectsForJujutsu(HlpObjects::FOR_JUJUTSU type, int atk, int def, int price, int recover);
	string getName();
	int getPrice();
	int getAttack();
	int getDefence();
	int getRecovery();
};

// Enemy Class
class Enemy
{
protected:
	string name;
	int attack;
	int defence;
	int expLost;
	int health;
public:
	virtual void setHealth(int amount) = 0;
	virtual string getName() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual int getDefense() = 0;
	virtual int getExpLost() = 0;
	virtual void takeDamage(int dmg) = 0;
	virtual bool isDefeated() = 0;
};

class WildEnemy : public Enemy
{
	Enemies::WILD type;
public:
	WildEnemy(Enemies::WILD type, int hp = 0, int atk = 0, int def = 0, int exp = 0);
	string getName();
	int getHealth();
	int getAttack();
	int getDefense();
	int getExpLost();
	void setHealth(int amount);
	void takeDamage(int dmg);
	bool isDefeated();
};

class DemonEnemy : public Enemy
{
	Enemies::DEMON type;
public:
	DemonEnemy(Enemies::DEMON type, int hp = 0, int atk = 0, int def = 0, int exp = 0);
	string getName();
	int getHealth();
	void setHealth(int amount);
	int getAttack();
	int getDefense();
	int getExpLost();
	void takeDamage(int dmg);
	bool isDefeated();
};

class JujutsuEnemy : public Enemy
{
	Enemies::JUJUTSU type;
public:
	JujutsuEnemy(Enemies::JUJUTSU type, int hp = 0, int atk = 0, int def = 0, int exp = 0);
	string getName();
	int getHealth();
	void setHealth(int amount);
	int getAttack();
	int getDefense();
	int getExpLost();
	void takeDamage(int dmg);
	bool isDefeated();
};

class CurseEnemy : public Enemy
{
	Enemies::CURSE type;
public:
	CurseEnemy(Enemies::CURSE type, int hp = 0, int atk = 0, int def = 0, int exp = 0);
	string getName();
	int getHealth();
	void setHealth(int amount);
	int getAttack();
	int getDefense();
	int getExpLost();
	void takeDamage(int dmg);
	bool isDefeated();
};
// SubPlaces
class SubPlaces
{
protected:
	string name;
	int noOfEnemies;
	int noOfObjects;
	bool finalBoss;
	HelpingObject* helpingobj[4];
	Enemy* enemies[4];
	int enemyCount;
	int objCount;
	int levelThreshold;
public:
	virtual int getNoOfEnemies() = 0;
	virtual int getNoOfObjects() = 0;
	virtual Enemy*& getEnemy() = 0;
	virtual HelpingObject*& getHelpingObj() = 0;
	virtual bool getBossInfo() = 0;
	virtual void setBossInfo(bool boss) = 0;
	virtual void addEnemy(Enemy& newEnemy) = 0;
	virtual void removeEnemy(Enemy& newEnemy) = 0;
	virtual void addHelpingObj(HelpingObject& newObj) = 0;
	virtual void removeHelpingObj(HelpingObject& newObj) = 0;
	virtual string getName() = 0;
	virtual int getLevelThreshold() = 0;
	virtual void setLevelThreshold(int level) = 0;
};

class WildForestSubPlaces : public SubPlaces
{
	Places::WILD_FOREST placeType;
	HlpObjects::FOR_WILD objType;
public:
	WildForestSubPlaces(Places::WILD_FOREST pType, HlpObjects::FOR_WILD oType, int enemy = 0, int obj = 0, int level = 1);
	int getNoOfEnemies();
	int getNoOfObjects();
	bool getBossInfo();
	void setBossInfo(bool boss);
	void addEnemy(Enemy& newEnemy);
	void removeEnemy(Enemy& newEnemy);
	Enemy*& getEnemy();
	HelpingObject*& getHelpingObj();
	void addHelpingObj(HelpingObject& newObj);
	void removeHelpingObj(HelpingObject& newObj);
	string getName() { return name; }
	int getLevelThreshold() { return levelThreshold; }
	void setLevelThreshold(int level) { levelThreshold = level; }
};

class CurseHouseSubPlaces : public SubPlaces
{
	Places::CURSED_HOUSE placeType;
	HlpObjects::FOR_CURSES objType;
public:
	CurseHouseSubPlaces(Places::CURSED_HOUSE pType, HlpObjects::FOR_CURSES oType, int enemy = 0, int obj = 0, int level = 1);
	int getNoOfEnemies();
	int getNoOfObjects();
	bool getBossInfo();
	void setBossInfo(bool boss);
	void addEnemy(Enemy& newEnemy);
	Enemy*& getEnemy();
	void removeEnemy(Enemy& newEnemy);
	HelpingObject*& getHelpingObj();
	void addHelpingObj(HelpingObject& newObj);
	void removeHelpingObj(HelpingObject& newObj);
	string getName() { return name; }
	int getLevelThreshold() { return levelThreshold; }
	void setLevelThreshold(int level) { levelThreshold = level; }
};

class DemonVillageSubPlaces : public SubPlaces
{
	Places::DEMON_VILLAGE placeType;
	HlpObjects::FOR_DEMONS objType;
public:
	DemonVillageSubPlaces(Places::DEMON_VILLAGE pType, HlpObjects::FOR_DEMONS oType, int enemy = 0, int obj = 0, int level = 1);
	int getNoOfEnemies();
	int getNoOfObjects();
	bool getBossInfo();
	void setBossInfo(bool boss);
	void addEnemy(Enemy& newEnemy);
	Enemy*& getEnemy();
	HelpingObject*& getHelpingObj();
	void removeEnemy(Enemy& newEnemy);
	void addHelpingObj(HelpingObject& newObj);
	void removeHelpingObj(HelpingObject& newObj);
	string getName() { return name; }
	int getLevelThreshold() { return levelThreshold; }
	void setLevelThreshold(int level) { levelThreshold = level; }
};

class JujutsuWorldSubPlaces : public SubPlaces
{
	Places::JUJUTSU_WORLD placeType;
	HlpObjects::FOR_JUJUTSU objType;
public:
	JujutsuWorldSubPlaces(Places::JUJUTSU_WORLD pType, HlpObjects::FOR_JUJUTSU oType, int enemy = 0, int obj = 0, int level = 1);
	int getNoOfEnemies();
	int getNoOfObjects();
	bool getBossInfo();
	void setBossInfo(bool boss);
	void addEnemy(Enemy& newEnemy);
	void removeEnemy(Enemy& newEnemy);
	HelpingObject*& getHelpingObj();
	Enemy*& getEnemy();
	void addHelpingObj(HelpingObject& newObj);
	void removeHelpingObj(HelpingObject& newObj);
	string getName() { return name; }
	int getLevelThreshold() { return levelThreshold; }
	void setLevelThreshold(int level) { levelThreshold = level; }
};

// Inventory Class
class Inventory
{
	HelpingObject* items[10];
	int itemCount;
public:
	Inventory();
	void addItem(HelpingObject* item);
	void removeItem(int index);
	HelpingObject* getItem(int index) const;
	int getItemCount() const;
	void displayInventory() const;
};

// Shop Class
class Shop
{
	HelpingObject* items[20];
	Teammates* teammates[4];
	int itemCount;
	int teammateCount;
public:
	Shop();
	void addItem(HelpingObject* item);
	void addTeammate(Teammates* teammate);
	void displayShop() const;
	HelpingObject* buyItem(int index, Player* player);
	Teammates* buyTeammate(int index, Player* player);
};

// Teammates Class
class Teammates
{
	string name;
	int attack;
	int defence;
	int health;
	int price;
public:
	Teammates(string n, int atk, int def, int hp, int pr);
	string getName() const { return name; }
	int getAttack() const { return attack; }
	int getDefence() const { return defence; }
	int getHealth() const { return health; }
	int getPrice() const { return price; }
	void takeDamage(int dmg);
	bool isDefeated() const { return health <= 0; }
};

// RoadMap Class
class RoadMap
{
public:
	static void printMap()
	{
		cout << "|-----------------------------------------------------|\n";
		cout << "| Stage-I: WILD FOREST                                |\n";
		cout << "| Trees -> Rocks -> River -> Dark Cave -> Stage Cleared!! |\n";
		cout << "|-----------------------------------------------------|\n\n";

		cout << "|---------------------------------------------------------------|\n";
		cout << "| Stage-II: CURSED HOUSE                                        |\n";
		cout << "| Lobby -> Kitchen -> Roof Top -> Sukuna Domain -> Stage Cleared!!  |\n";
		cout << "|---------------------------------------------------------------|\n\n";

		cout << "|--------------------------------------------------------------------------|\n";
		cout << "| Stage-III: DEMON VILLAGE                                                 |\n";
		cout << "| Bridge -> Broken House -> Demon Castle -> Infinity Castle -> Stage Cleared!! |\n";
		cout << "|--------------------------------------------------------------------------|\n\n";

		cout << "|-------------------------------------------------------------------------------------------|\n";
		cout << "| Stage-IV: JUJUTSU WORLD                                                                   |\n";
		cout << "| Tengen's Barrier -> Jujutsu High -> Shibuya -> Gojo's Domain Infinite Void -> Stage Cleared!! |\n";
		cout << "|-------------------------------------------------------------------------------------------|\n\n";
	}
};

// Player Class
class Player
{
protected:
	string name;
	int attack;
	int defence;
	int health;
	int points;
	int exp;
	int level;
	string techName;
	bool foundKey;
	Teammates* teammates[3];
	static int playerCount;
public:
	int teammateCount;
	Player(const Player& other);
	Player() {};
	virtual string getName() const = 0;
	virtual int getAttack() const = 0;
	virtual Teammates& getTeammates(int i) = 0;
	virtual int getDefence() const = 0;
	virtual void setDefence(int defence) = 0;
	virtual int getHealth() const = 0;
	virtual int getPoints() const = 0;
	virtual int getExp() const = 0;
	virtual int getLevel() const = 0;
	virtual void setAttack(int newAttack) = 0;
	virtual bool hasFoundKey() const = 0;
	virtual void setHealth(int health) = 0;
	virtual void setPoints(int points) = 0;
	virtual void setExp(int exp) = 0;
	virtual void setLevel(int level) = 0;
	virtual void setFoundKey(bool foundKey) = 0;
	virtual void victoryDialogue() = 0;
	virtual void takeDamage(int dmg) = 0;
	void addTeammate(Teammates* teammate);
	void displayTeammates() const;
	static int getPlayerCount() { return playerCount; }
};

class Gojo : public Player
{
	bool domainExpansion;
	bool limitlessTech;
	bool sixEye;
public:
	Gojo(string n, int atk, int hp, int def, int pt);
	Gojo(const Gojo& other);
	string getName() const;
	int getAttack() const;
	void setAttack(int newAttack);
	int getDefence() const;
	Teammates& getTeammates(int i);
	void setDefence(int defence);
	int getHealth() const;
	int getPoints() const;
	int getExp() const;
	int getLevel() const;
	bool hasFoundKey() const;
	void setHealth(int health);
	void setPoints(int points);
	void setExp(int exp);
	void setLevel(int level);
	void setFoundKey(bool foundKey);
	void victoryDialogue();
	void setTechnique(HlpObjects::FOR_JUJUTSU tech);
	void takeDamage(int dmg);
};

class Tanjiro : public Player
{
	bool rage;
	bool breathingTech;
	HlpObjects::FOR_DEMONS type;
public:
	Tanjiro(string n, int atk, int hp, int def, int pt);
	Tanjiro(const Tanjiro& other);
	string getName() const;
	int getAttack() const;
	void setAttack(int newAttack);
	int getDefence() const;
	void setDefence(int defence);
	int getHealth() const;
	int getPoints() const;
	int getExp() const;
	Teammates& getTeammates(int i);
	int getLevel() const;
	bool hasFoundKey() const;
	void setHealth(int health);
	void setPoints(int points);
	void setExp(int exp);
	void setLevel(int level);
	void setFoundKey(bool foundKey);
	void victoryDialogue();
	void setTechnique(HlpObjects::FOR_DEMONS tech);
	void takeDamage(int dmg);
};

class Yuta : public Player
{
	bool domainExpansion;
public:
	Yuta(string n, int atk, int hp, int def, int pt);
	Yuta(const Yuta& other);
	string getName() const;
	int getAttack() const;
	void setAttack(int newAttack);
	int getDefence() const;
	void setDefence(int defence);
	int getHealth() const;
	int getPoints() const;
	int getExp() const;
	Teammates& getTeammates(int i);
	int getLevel() const;
	bool hasFoundKey() const;
	void setHealth(int health);
	void setPoints(int points);
	void setExp(int exp);
	void setLevel(int level);
	void setFoundKey(bool foundKey);
	void victoryDialogue();
	void setTechnique(HlpObjects::FOR_JUJUTSU tech);
	void takeDamage(int dmg);
};

class Zenitsu : public Player
{
	bool isSleep;
	bool breathingTech;
	HlpObjects::FOR_DEMONS type;
public:
	Zenitsu(string n, int atk, int hp, int def, int pt);
	Zenitsu(const Zenitsu& other);
	string getName() const;
	int getAttack() const;
	void setAttack(int newAttack);
	int getDefence() const;
	void setDefence(int defence);
	int getHealth() const;
	int getPoints() const;
	int getExp() const;
	int getLevel() const;
	bool hasFoundKey() const;
	void setHealth(int health);
	void setPoints(int points);
	Teammates& getTeammates(int i);
	void setExp(int exp);
	void setLevel(int level);
	void setFoundKey(bool foundKey);
	void victoryDialogue();
	void setTechnique(HlpObjects::FOR_DEMONS tech);
	void takeDamage(int dmg);
};

// ManageStats Class
class ManageStats
{
	Player* player;
public:
	ManageStats(Player* p);
	void increaseHealth(int amount);
	void increaseAttack(int amount);
	void increaseDefence(int amount);
	void levelUp();
};

class Place
{
protected:
	int totalEnemies;
	int totalObjects;
	int count;
	bool locked;
	SubPlaces* connectedPlaces[4];
public:
	virtual int getTotalEnemies() = 0;
	virtual bool getLocked() = 0;
	virtual void setLocked(bool lock) = 0;
	virtual int getTotalObjects() = 0;
	virtual void addConnectedPlace(SubPlaces& subPlace) = 0;
	virtual void calculateTotal() = 0;
	virtual string getName() = 0;
};

class DemonVillage : public Place
{
public:
	DemonVillage();
	int getTotalEnemies();
	int getTotalObjects();
	bool getLocked();
	void setLocked(bool lock);
	void addConnectedPlace(SubPlaces& subPlace);
	void calculateTotal();
	string getName() { return "Demon Village"; }
};

class CursedHouse : public Place
{
public:
	CursedHouse();
	int getTotalEnemies();
	int getTotalObjects();
	bool getLocked();
	void setLocked(bool lock);
	void addConnectedPlace(SubPlaces& subPlace);
	void calculateTotal();
	string getName() { return "Cursed House"; }
};

class WildForest : public Place
{
public:
	WildForest();
	int getTotalEnemies();
	bool getLocked();
	void setLocked(bool lock);
	int getTotalObjects();
	void addConnectedPlace(SubPlaces& subPlace);
	void calculateTotal();
	string getName() { return "Wild Forest"; }
};

class JujutsuWorld : public Place
{
public:
	JujutsuWorld();
	int getTotalEnemies();
	int getTotalObjects();
	bool getLocked();
	void setLocked(bool lock);
	void addConnectedPlace(SubPlaces& subPlace);
	void calculateTotal();
	string getName() { return "Jujutsu World"; }
};

// GameManager Class
class GameManager
{
private:
	Player* currentPlayer;
	Place* currentPlace;
	int currentStage;
	int currentSubPlaceIndex;
	bool gameRunning;
	string battleHistory[100];
	int historyCount;
public:
	GameManager();
	void startGame(Player* player);
	void endGame();
	void setCurrentStage(int stage);
	void setSubPlaceIndex(int index);
	int getCurrentStage() const;
	int getSubPlaceIndex() const;
	void changePlace(Place* newPlace);
	void battle(Enemy* enemy, Inventory* inventory, SubPlaces* subPlace);
	bool isGameRunning() const;
	void saveGame(const Inventory* inventory, const string& filename);
	void loadGame(Player*& player, Inventory* inventory, string& filename);
	void addBattleLog(const string& log);
	void viewBattleHistory() const;
	void finalScoreReport(const Inventory* inventory) const;
};
