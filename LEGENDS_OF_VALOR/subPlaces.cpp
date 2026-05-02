#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

//--------------- Wild Forest SubPlaces ---------------\\

WildForestSubPlaces::WildForestSubPlaces(Places::WILD_FOREST pType, HlpObjects::FOR_WILD oType, int enemy, int obj, int level)
{
	switch (pType)
	{
	case Places::RIVER:
		name = "River";
		levelThreshold = level;
		break;
	case Places::ROCKS:
		name = "Rocks";
		levelThreshold = level;
		break;
	case Places::CAVE:
		name = "Dark Cave";
		levelThreshold = level;
		break;
	case Places::TREES:
		name = "Huge Trees";
		levelThreshold = level;
		break;
	default:
		cout << "Invalid Type!\n";
		name = "\0";
		levelThreshold = 1;
	}
	objCount = 0;
	enemyCount = 0;
	placeType = pType;
	objType = oType;
	noOfEnemies = enemy;
	noOfObjects = obj;
	finalBoss = false;
	for (int i = 0; i < 4; i++)
	{
		enemies[i] = nullptr;
		helpingobj[i] = nullptr;
	}
}

int WildForestSubPlaces::getNoOfEnemies() { return enemyCount; }
int WildForestSubPlaces::getNoOfObjects()
{
	return objCount;
}
bool WildForestSubPlaces::getBossInfo() { return finalBoss; }
void WildForestSubPlaces::setBossInfo(bool boss) { finalBoss = boss; }

void WildForestSubPlaces::addEnemy(Enemy& newEnemy)
{
	if (enemyCount < 4)
	{
		enemies[enemyCount] = &newEnemy;
		enemyCount++;
		cout << newEnemy.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more enemies!\n";
}

void WildForestSubPlaces::removeEnemy(Enemy& newEnemy)
{
	int index = -1;
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] == &newEnemy)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < enemyCount - 1; i++)
			enemies[i] = enemies[i + 1];
		enemies[enemyCount - 1] = nullptr;
		enemyCount--;
		cout << newEnemy.getName() << " removed from " << name << endl;
	}
}

void WildForestSubPlaces::addHelpingObj(HelpingObject& newObj)
{
	if (objCount < 4)
	{
		helpingobj[objCount] = &newObj;
		objCount++;
		cout << newObj.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more objects!\n";
}

void WildForestSubPlaces::removeHelpingObj(HelpingObject& newObj)
{
	int index = -1;
	for (int i = 0; i < objCount; i++)
	{
		if (helpingobj[i] == &newObj)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < objCount - 1; i++)
			helpingobj[i] = helpingobj[i + 1];
		helpingobj[objCount - 1] = nullptr;
		objCount--;
		cout << newObj.getName() << " removed from " << name << endl;
	}
}

HelpingObject*& WildForestSubPlaces::getHelpingObj()
{
	return *helpingobj;
}
Enemy*& WildForestSubPlaces::getEnemy()
{
	return *enemies;
}

//--------------- Demon Village SubPlaces ---------------\\

DemonVillageSubPlaces::DemonVillageSubPlaces(Places::DEMON_VILLAGE pType, HlpObjects::FOR_DEMONS oType, int enemy, int obj, int level)
{
	switch (pType)
	{
	case Places::BRIDGE:
		name = "Broken Bridge";
		levelThreshold = level;
		break;
	case Places::BROKEN_HOUSE:
		name = "Broken House";
		levelThreshold = level;
		break;
	case Places::DEMON_CASTLE:
		name = "Demon Castle";
		levelThreshold = level;
		break;
	case Places::INFINITY_CASTLE:
		name = "Infinity Castle";
		levelThreshold = level;
		break;
	default:
		cout << "Invalid Type!\n";
		name = "\0";
		levelThreshold = 1;
	}
	objCount = 0;
	enemyCount = 0;
	placeType = pType;
	objType = oType;
	noOfEnemies = enemy;
	noOfObjects = obj;
	finalBoss = false;
	for (int i = 0; i < 4; i++)
	{
		enemies[i] = nullptr;
		helpingobj[i] = nullptr;
	}
}

int DemonVillageSubPlaces::getNoOfEnemies() { return enemyCount; }
int DemonVillageSubPlaces::getNoOfObjects() { return objCount; }
bool DemonVillageSubPlaces::getBossInfo() { return finalBoss; }
void DemonVillageSubPlaces::setBossInfo(bool boss) { finalBoss = boss; }

void DemonVillageSubPlaces::addEnemy(Enemy& newEnemy)
{
	if (enemyCount < 4)
	{
		enemies[enemyCount] = &newEnemy;
		enemyCount++;
		cout << newEnemy.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more enemies!\n";
}

void DemonVillageSubPlaces::removeEnemy(Enemy& newEnemy)
{
	int index = -1;
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] == &newEnemy)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < enemyCount - 1; i++)
			enemies[i] = enemies[i + 1];
		enemies[enemyCount - 1] = nullptr;
		enemyCount--;
		cout << newEnemy.getName() << " removed from " << name << endl;
	}
}

void DemonVillageSubPlaces::addHelpingObj(HelpingObject& newObj)
{
	if (objCount < 4)
	{
		helpingobj[objCount] = &newObj;
		objCount++;
		cout << newObj.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more objects!\n";
}

void DemonVillageSubPlaces::removeHelpingObj(HelpingObject& newObj)
{
	int index = -1;
	for (int i = 0; i < objCount; i++)
	{
		if (helpingobj[i] == &newObj)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < objCount - 1; i++)
			helpingobj[i] = helpingobj[i + 1];
		helpingobj[objCount - 1] = nullptr;
		objCount--;
		cout << newObj.getName() << " removed from " << name << endl;
	}
}

HelpingObject*& DemonVillageSubPlaces::getHelpingObj()
{
	return *helpingobj;
}
Enemy*& DemonVillageSubPlaces::getEnemy()
{
	return *enemies;
}

//--------------- Curse House SubPlaces ---------------\\

CurseHouseSubPlaces::CurseHouseSubPlaces(Places::CURSED_HOUSE pType, HlpObjects::FOR_CURSES oType, int enemy, int obj, int level)
{
	switch (pType)
	{
	case Places::LOBBY:
		name = "Cursed Lobby";
		levelThreshold = level;
		break;
	case Places::KITCHEN:
		name = "Bloody Kitchen";
		levelThreshold = level;
		break;
	case Places::ROOF_TOP:
		name = "Dark Roof-Top";
		levelThreshold = level;
		break;
	case Places::SUKUNA_DOMAIN:
		name = "Sukuna's Domain Malevolent Shrine";
		levelThreshold = level;
		break;
	default:
		cout << "Invalid Type!\n";
		name = "\0";
		levelThreshold = 1;
	}
	objCount = 0;
	enemyCount = 0;
	placeType = pType;
	objType = oType;
	noOfEnemies = enemy;
	noOfObjects = obj;
	finalBoss = false;
	for (int i = 0; i < 4; i++)
	{
		enemies[i] = nullptr;
		helpingobj[i] = nullptr;
	}
}

int CurseHouseSubPlaces::getNoOfObjects() { return objCount; }
int CurseHouseSubPlaces::getNoOfEnemies() { return enemyCount; }
bool CurseHouseSubPlaces::getBossInfo() { return finalBoss; }
void CurseHouseSubPlaces::setBossInfo(bool boss) { finalBoss = boss; }

void CurseHouseSubPlaces::addEnemy(Enemy& newEnemy)
{
	if (enemyCount < 4)
	{
		enemies[enemyCount] = &newEnemy;
		enemyCount++;
		cout << newEnemy.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more enemies!\n";
}

void CurseHouseSubPlaces::removeEnemy(Enemy& newEnemy)
{
	int index = -1;
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] == &newEnemy)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < enemyCount - 1; i++)
			enemies[i] = enemies[i + 1];
		enemies[enemyCount - 1] = nullptr;
		enemyCount--;
		cout << newEnemy.getName() << " removed from " << name << endl;
	}
}

void CurseHouseSubPlaces::addHelpingObj(HelpingObject& newObj)
{
	if (objCount < 4)
	{
		helpingobj[objCount] = &newObj;
		objCount++;
		cout << newObj.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more objects!\n";
}

void CurseHouseSubPlaces::removeHelpingObj(HelpingObject& newObj)
{
	int index = -1;
	for (int i = 0; i < objCount; i++)
	{
		if (helpingobj[i] == &newObj)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < objCount - 1; i++)
			helpingobj[i] = helpingobj[i + 1];
		helpingobj[objCount - 1] = nullptr;
		objCount--;
		cout << newObj.getName() << " removed from " << name << endl;
	}
}

HelpingObject*& CurseHouseSubPlaces::getHelpingObj()
{
	return *helpingobj;
}
Enemy*& CurseHouseSubPlaces::getEnemy()
{
	return *enemies;
}

//--------------- JJK World SubPlaces ---------------\\

JujutsuWorldSubPlaces::JujutsuWorldSubPlaces(Places::JUJUTSU_WORLD pType, HlpObjects::FOR_JUJUTSU oType, int enemy, int obj, int level)
{
	switch (pType)
	{
	case Places::TENGEN_PLACE:
		name = "Tengen's Barrier";
		levelThreshold = level;
		break;
	case Places::JJK_HIGH:
		name = "Jujutsu High";
		levelThreshold = level;
		break;
	case Places::SHIBUYA:
		name = "Shibuya";
		levelThreshold = level;
		break;
	case Places::GOJO_DOMAIN:
		name = "Gojo's Domain Infinite Void";
		levelThreshold = level;
		break;
	default:
		cout << "Invalid Type!\n";
		name = "\0";
		levelThreshold = 1;
	}
	objCount = 0;
	enemyCount = 0;
	placeType = pType;
	objType = oType;
	noOfEnemies = enemy;
	noOfObjects = obj;
	finalBoss = false;
	for (int i = 0; i < 4; i++)
	{
		enemies[i] = nullptr;
		helpingobj[i] = nullptr;
	}
}

int JujutsuWorldSubPlaces::getNoOfEnemies() { return enemyCount; }
int JujutsuWorldSubPlaces::getNoOfObjects() { return objCount; }
bool JujutsuWorldSubPlaces::getBossInfo() { return finalBoss; }
void JujutsuWorldSubPlaces::setBossInfo(bool boss) { finalBoss = boss; }

void JujutsuWorldSubPlaces::addEnemy(Enemy& newEnemy)
{
	if (enemyCount < 4)
	{
		enemies[enemyCount] = &newEnemy;
		enemyCount++;
		cout << newEnemy.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more enemies!\n";
}

void JujutsuWorldSubPlaces::removeEnemy(Enemy& newEnemy)
{
	int index = -1;
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemies[i] == &newEnemy)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < enemyCount - 1; i++)
			enemies[i] = enemies[i + 1];
		enemies[enemyCount - 1] = nullptr;
		enemyCount--;
		cout << newEnemy.getName() << " removed from " << name << endl;
	}
}

void JujutsuWorldSubPlaces::addHelpingObj(HelpingObject& newObj)
{
	if (objCount < 4)
	{
		helpingobj[objCount] = &newObj;
		objCount++;
		cout << newObj.getName() << " added successfully to " << name << endl;
	}
	else
		cout << "Cannot add more objects!\n";
}

void JujutsuWorldSubPlaces::removeHelpingObj(HelpingObject& newObj)
{
	int index = -1;
	for (int i = 0; i < objCount; i++)
	{
		if (helpingobj[i] == &newObj)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		for (int i = index; i < objCount - 1; i++)
			helpingobj[i] = helpingobj[i + 1];
		helpingobj[objCount - 1] = nullptr;
		objCount--;
		cout << newObj.getName() << " removed from " << name << endl;
	}
}

HelpingObject*& JujutsuWorldSubPlaces::getHelpingObj()
{
	return *helpingobj;
}
Enemy*& JujutsuWorldSubPlaces::getEnemy()
{
	return *enemies;
}