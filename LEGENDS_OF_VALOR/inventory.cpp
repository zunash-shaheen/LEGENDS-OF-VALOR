#include<iostream>
#include<string>
#include"Classes.h"

using namespace std;

Inventory::Inventory() : itemCount(0) {}

void Inventory::addItem(HelpingObject* item)
{
	if (itemCount < 10)
	{
		items[itemCount] = item;
		itemCount++;
	}
	else
		cout << "Inventory already full\n";
}

void Inventory::removeItem(int index)
{
	if (index >= 0 && index < itemCount)
	{
		for (int i = index; i < itemCount - 1; i++)
		{
			items[i] = items[i + 1];
		}
		itemCount--;
	}
}

HelpingObject* Inventory::getItem(int index) const
{
	if (index >= 0 && index < itemCount)
		return items[index];

	return nullptr;
}

int Inventory::getItemCount() const
{
	return itemCount;
}

void Inventory::displayInventory() const
{
	if (itemCount == 0)
		cout << "No Items in Inventory!\n";
	for (int i = 0; i < itemCount; i++)
	{
		cout << i + 1 << ". " << items[i]->getName() << endl;
	}
}