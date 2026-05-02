#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

//--------------- Shop ---------------\\

Shop::Shop() : itemCount(0), teammateCount(0)
{
	for (int i = 0; i < 20; i++)
		items[i] = nullptr;
	for (int i = 0; i < 4; i++)
		teammates[i] = nullptr;
}

void Shop::addItem(HelpingObject* item)
{
	if (itemCount < 20)
	{
		items[itemCount] = item;
		itemCount++;
	}
}

void Shop::addTeammate(Teammates* teammate)
{
	if (teammateCount < 4)
	{
		teammates[teammateCount] = teammate;
		teammateCount++;
	}
}

void Shop::displayShop() const
{
	cout << "Shop Items:\n";
	for (int i = 0; i < itemCount; i++)
		cout << i + 1 << ". " << items[i]->getName() << " (Price: " << items[i]->getPrice() << ")\n";
	cout << "\nAvailable Teammates:\n";
	for (int i = 0; i < teammateCount; i++)
		cout << i + 1 << ". " << teammates[i]->getName() << " (Price: " << teammates[i]->getPrice() << ")\n";
}

HelpingObject* Shop::buyItem(int index, Player* player)
{
	if (index >= 1 && index <= itemCount)
	{
		HelpingObject* item = items[index - 1];
		if (player->getPoints() >= item->getPrice())
		{
			player->setPoints(player->getPoints() - item->getPrice());
			cout << "Purchased " << item->getName() << "!\n";
			return item;
		}
		else
			cout << "Not enough points!\n";
	}
	else
		cout << "Invalid Choice!!";
	return nullptr;
}

Teammates* Shop::buyTeammate(int index, Player* player)
{
	if (index >= 1 && index <= teammateCount)
	{
		Teammates* teammate = teammates[index - 1];
		if (player->getPoints() >= teammate->getPrice())
		{
			player->setPoints(player->getPoints() - teammate->getPrice());
			cout << "Recruited " << teammate->getName() << "!\n";
			return teammate;
		}
		else
			cout << "Not enough points!\n";
	}
	return nullptr;
}

//--------------- Teammates ---------------\\

Teammates::Teammates(string n, int atk, int def, int hp, int pr) : name(n), attack(atk), defence(def), health(hp), price(pr) {}

void Teammates::takeDamage(int dmg)
{
	int damage = abs(defence - dmg);
	if (health - damage < 0)
		health = 0;
	else
		health -= damage;
	cout << name << " took " << damage << " damage!\n";
}