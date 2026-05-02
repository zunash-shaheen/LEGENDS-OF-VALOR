#include<iostream>
#include<string>
#include"Classes.h"

using namespace std;

ManageStats::ManageStats(Player* p) : player(p) {}

void ManageStats::increaseHealth(int amount)
{
	player->setHealth(player->getHealth() + amount);
}

void ManageStats::increaseAttack(int amount)
{
	player->setAttack(player->getAttack() + amount);
}

void ManageStats::increaseDefence(int amount)
{
	player->setDefence(player->getDefence() + amount);
}

void ManageStats::levelUp()
{
	player->setLevel(player->getLevel() + 1);
}