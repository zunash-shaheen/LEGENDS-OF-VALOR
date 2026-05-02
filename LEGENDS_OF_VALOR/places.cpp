#include<iostream>
#include<string>
#include"Classes.h"
using namespace std;

//--------------- Wild Forest ---------------\\

WildForest::WildForest()
{
	count = 0;
	totalEnemies = 0;
	totalObjects = 0;
	locked = true;
}
int WildForest::getTotalEnemies()
{
	return totalEnemies;
}
int WildForest::getTotalObjects()
{
	return totalObjects;
}
void WildForest::addConnectedPlace(SubPlaces& subPlace)
{
	if (count < 4)
	{
		connectedPlaces[count] = &subPlace;
		count++;
	}
	else
		cout << "Cannot add more Areas\n";
}

bool WildForest::getLocked() { return locked; }
void WildForest::setLocked(bool lock)
{
	locked = lock;
}
void WildForest::calculateTotal()
{
	for (int i = 0; i < 4; i++)
	{
		totalEnemies += connectedPlaces[i]->getNoOfEnemies();
		totalObjects += connectedPlaces[i]->getNoOfObjects();
	}
}

//--------------- Cursed House ---------------\\

CursedHouse::CursedHouse()
{
	count = 0;
	locked = true;
	totalEnemies = 0;
	totalObjects = 0;
}

bool CursedHouse::getLocked() { return locked; }
void CursedHouse::setLocked(bool lock)
{
	locked = lock;
}
int CursedHouse::getTotalEnemies()
{
	return totalEnemies;
}
int CursedHouse::getTotalObjects()
{
	return totalObjects;
}
void CursedHouse::addConnectedPlace(SubPlaces& subPlace)
{
	if (count < 4)
	{
		connectedPlaces[count] = &subPlace;
		count++;
	}
	else
		cout << "Cannot add more Areas\n";
}
void CursedHouse::calculateTotal()
{
	for (int i = 0; i < 4; i++)
	{
		totalEnemies += connectedPlaces[i]->getNoOfEnemies();
		totalObjects += connectedPlaces[i]->getNoOfObjects();
	}
}

//--------------- Demon Village ---------------\\

DemonVillage::DemonVillage()
{
	count = 0;
	totalEnemies = 0;
	locked = true;
	totalObjects = 0;
}
int DemonVillage::getTotalEnemies()
{
	return totalEnemies;
}
int DemonVillage::getTotalObjects()
{
	return totalObjects;
}
void DemonVillage::addConnectedPlace(SubPlaces& subPlace)
{
	if (count < 4)
	{
		connectedPlaces[count] = &subPlace;
		count++;
	}
	else
		cout << "Cannot add more Areas\n";
}
void DemonVillage::calculateTotal()
{
	for (int i = 0; i < 4; i++)
	{
		totalEnemies += connectedPlaces[i]->getNoOfEnemies();
		totalObjects += connectedPlaces[i]->getNoOfObjects();
	}
}

bool DemonVillage::getLocked() { return locked; }
void DemonVillage::setLocked(bool lock)
{
	locked = lock;
}

//--------------- JJK World ---------------\\

JujutsuWorld::JujutsuWorld()
{
	count = 0;
	totalEnemies = 0;
	locked = true;
	totalObjects = 0;
}
int JujutsuWorld::getTotalEnemies()
{
	return totalEnemies;
}
int JujutsuWorld::getTotalObjects()
{
	return totalObjects;
}
void JujutsuWorld::addConnectedPlace(SubPlaces& subPlace)
{
	if (count < 4)
	{
		connectedPlaces[count] = &subPlace;
		count++;
	}
	else
		cout << "Cannot add more Areas\n";
}

void JujutsuWorld::calculateTotal()
{
	for (int i = 0; i < 4; i++)
	{
		totalEnemies += connectedPlaces[i]->getNoOfEnemies();
		totalObjects += connectedPlaces[i]->getNoOfObjects();
	}
}

bool JujutsuWorld::getLocked() { return locked; }
void JujutsuWorld::setLocked(bool lock)
{
	locked = lock;
}