#include<iostream>
#include<string>
#include"Classes.h"
using namespace std;

//--------------- Wild Forest Enemies ---------------\\

WildEnemy::WildEnemy(Enemies::WILD type, int hp, int atk, int def, int exp)
{
	health = hp;
	attack = atk;
	defence = def;
	expLost = exp;
	switch (type)
	{
	case Enemies::LION: name = "Lion";
		break;
	case Enemies::TIGER: name = "Tiger";
		break;
	case Enemies::SNAKE: name = "Snake";
		break;
	case Enemies::BEAST: name = "Beast";
		break;
	default: name = "\0";
	}
}

string WildEnemy::getName()
{
	return name;
}

int WildEnemy::getHealth() { return health; }
int WildEnemy::getAttack() { return attack; }
int WildEnemy::getDefense() { return defence; }
int WildEnemy::getExpLost() { return expLost; }

void  WildEnemy::setHealth(int amount)
{
	health += amount;
}

void WildEnemy::takeDamage(int amount)
{
	int damage = abs(defence - amount);
	if (health - damage <= 0)
		health = 0;
	else
		health -= damage;
	cout << damage << " of Damage Taken by " << name << "!!" << endl;
}

bool WildEnemy::isDefeated()
{
	if (health <= 0)
		return true;
	return false;
}

//--------------- Demon Village Enemies ---------------\\

DemonEnemy::DemonEnemy(Enemies::DEMON type, int hp, int atk, int def, int exp)
{
	health = hp;
	attack = atk;
	defence = def;
	expLost = exp;
	switch (type)
	{
	case Enemies::UPPER_DEMONS: name = "Upper Demon";
		break;
	case Enemies::LOWER_MOON: name = "Lower Moon";
		break;
	case Enemies::UPPER_MOON: name = "Upper Moon-3 Akaza";
		break;
	case Enemies::DEMON_KING: name = "Demon King Muzan";
		break;
	default: name = "\0";
	}
}
void  DemonEnemy::setHealth(int amount)
{
	health += amount;
}

string DemonEnemy::getName()
{
	return name;
}

int DemonEnemy::getHealth() { return health; }
int DemonEnemy::getAttack() { return attack; }
int DemonEnemy::getDefense() { return defence; }
int DemonEnemy::getExpLost() { return expLost; }

void DemonEnemy::takeDamage(int amount)
{
	int damage = abs(defence - amount);
	if (health - damage <= 0)
		health = 0;
	else
		health -= damage;
	cout << damage << " of Damage Taken by " << name << "!!" << endl;
}

bool DemonEnemy::isDefeated()
{
	if (health <= 0)
		return true;
	return false;
}

//--------------- Cursed House Enemies ---------------\\

CurseEnemy::CurseEnemy(Enemies::CURSE type, int hp, int atk, int def, int exp)
{
	health = hp;
	attack = atk;
	defence = def;
	expLost = exp;
	switch (type)
	{
	case Enemies::CURSES: name = "Curse Spirit";
		break;
	case Enemies::VAMPIRE: name = "Vampire";
		break;
	case Enemies::BAD_SPIRIT: name = "Special Grade Curse Jogo";
		break;
	case Enemies::KING_OF_CURSES: name = "King of Curses Sukuna";
		break;
	default: name = "\0";
	}
}

string CurseEnemy::getName()
{
	return name;
}

int CurseEnemy::getHealth() { return health; }
int CurseEnemy::getAttack() { return attack; }
int CurseEnemy::getDefense() { return defence; }
int CurseEnemy::getExpLost() { return expLost; }

void CurseEnemy::takeDamage(int amount)
{
	int damage = abs(defence - amount);
	if (health - damage <= 0)
		health = 0;
	else
		health -= damage;
	cout << damage << " of Damage Taken by " << name << "!!" << endl;
}

void  CurseEnemy::setHealth(int amount)
{
	health += amount;
}
bool CurseEnemy::isDefeated()
{
	if (health <= 0)
		return true;
	return false;
}

//--------------- JJk Enemies ---------------\\

JujutsuEnemy::JujutsuEnemy(Enemies::JUJUTSU type, int hp, int atk, int def, int exp)
{
	health = hp;
	attack = atk;
	defence = def;
	expLost = exp;
	switch (type)
	{
	case Enemies::GRADE_I: name = "Grade I Sorcerer";
		break;
	case Enemies::GRADE_II: name = "Grade II Sorcerer";
		break;
	case Enemies::GRADE_III: name = "Grade III Sorcerer";
		break;
	case Enemies::SPECIAL_GRADE: name = "Special Grade Sorcerer Saturu Gojo";
		break;
	default: name = "\0";
	}
}

void  JujutsuEnemy::setHealth(int amount)
{
	health += amount;
}
string JujutsuEnemy::getName()
{
	return name;
}

int JujutsuEnemy::getHealth() { return health; }
int JujutsuEnemy::getAttack() { return attack; }
int JujutsuEnemy::getDefense() { return defence; }
int JujutsuEnemy::getExpLost() { return expLost; }

void JujutsuEnemy::takeDamage(int amount)
{
	int damage = abs(defence - amount);
	if (health - damage <= 0)
		health = 0;
	else
		health -= damage;
	cout << damage << " of Damage Taken by " << name << "!!" << endl;
}

bool JujutsuEnemy::isDefeated()
{
	if (health <= 0)
		return true;
	return false;
}