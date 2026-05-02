#include <iostream>
#include <string>
#include "Classes.h"
#include <cstdlib>

using namespace std;

int Player::playerCount = 0;

Player::Player(const Player& other)
{
	name = other.name;
	attack = other.attack;
	defence = other.defence;
	health = other.health;
	points = other.points;
	exp = other.exp;
	level = other.level;
	techName = other.techName;
	foundKey = other.foundKey;
	teammateCount = other.teammateCount;
	for (int i = 0; i < teammateCount; i++)
		teammates[i] = new Teammates(*other.teammates[i]);
	playerCount++;
}

void Player::addTeammate(Teammates* teammate)
{
	if (teammateCount < 3)
	{
		teammates[teammateCount] = teammate;
		cout << teammate->getName() << " joined the team!\n";
		teammateCount++;
	}
	else
		cout << "Team is full!\n";
}

void Player::displayTeammates() const
{
	if (teammateCount == 0)
	{
		cout << "No Available Teammates!! You can go to Shop to buy Teammates\n";
		return;
	}
	cout << "Teammates:\n";
	for (int i = 0; i < teammateCount; i++)
		if (!teammates[i]->isDefeated())
			cout << i + 1 << ". " << teammates[i]->getName() << " (HP: " << teammates[i]->getHealth() << ")\n";
}

//--------------- Gojo ---------------\\

Gojo::Gojo(string n, int atk, int hp, int def, int pt)
{
	name = n;
	attack = atk;
	defence = def;
	health = hp;
	points = pt;
	exp = 0;
	level = 1;
	techName = "\0";
	foundKey = false;
	domainExpansion = false;
	limitlessTech = false;
	sixEye = false;
	teammateCount = 0;
	playerCount++;
	for (int i = 0; i < 4; i++)
		teammates[i] = nullptr;
}

Teammates& Gojo::getTeammates(int i)
{
	return *teammates[i];
}
Gojo::Gojo(const Gojo& other) : Player(other)
{
	domainExpansion = other.domainExpansion;
	limitlessTech = other.limitlessTech;
	sixEye = other.sixEye;
}

string Gojo::getName() const { return name; }
int Gojo::getAttack() const { return attack; }
void Gojo::setAttack(int newAttack)
{
	attack = newAttack;
	if (limitlessTech)
		attack += 30;
}
int Gojo::getDefence() const { return defence; }
void Gojo::setDefence(int newDefence)
{
	defence = newDefence;
	if (sixEye)
		defence = 50;
	else if (limitlessTech)
		defence += 70;
}
int Gojo::getHealth() const { return health; }
int Gojo::getPoints() const { return points; }
int Gojo::getExp() const { return exp; }
int Gojo::getLevel() const { return level; }
bool Gojo::hasFoundKey() const { return foundKey; }
void Gojo::setHealth(int health) { this->health = health; }
void Gojo::setPoints(int points) { this->points = points; }
void Gojo::setExp(int exp) { this->exp = exp; }
void Gojo::setLevel(int level) { this->level = level; }
void Gojo::setFoundKey(bool foundKey) { this->foundKey = foundKey; }
void Gojo::victoryDialogue()
{
	cout << "Gojo: 'You're too weak!'\n";
}
void Gojo::setTechnique(HlpObjects::FOR_JUJUTSU tech)
{
	switch (tech)
	{
	case HlpObjects::FOR_JUJUTSU::SIX_EYES:
		techName = "Six Eyes";
		sixEye = true;
		break;
	case HlpObjects::FOR_JUJUTSU::REVERSE_CURSE_TECHNIQUE:
		techName = "Reverse Curse Technique";
		break;
	case HlpObjects::FOR_JUJUTSU::SPECIAL_GRADE_ITEM:
		techName = "Special Grade Item";
		break;
	case HlpObjects::FOR_JUJUTSU::DOMAIN_EXPANSION:
		techName = "Domain Expansion";
		domainExpansion = true;
		break;
	case HlpObjects::FOR_JUJUTSU::LIMITLESS_TECHNIQUE:
		techName = "Limitless Technique";
		limitlessTech = true;
		break;
	default:
		techName = "\0";
	}
}void Gojo::takeDamage(int dmg)
{
	bool infinityActive = false;
	if (rand() % 100 > 40)
		infinityActive = true;

	if (infinityActive)
	{
		cout << name << "'s Infinity blocked the attack! No damage taken!\n";
		return;
	}

	bool isCritical = false;
	if (rand() % 100 > 5)
		isCritical = true;

	if (isCritical)
	{
		dmg = 0;
		cout << "UNLIMITED VOID! Attack nullified!\n";
	}

	int damageTaken = dmg - (defence * 2);
	if (damageTaken <= 0)
		damageTaken = 10;

	health -= damageTaken;
	if (health < 0)
		health = 0;

	cout << name << " took " << damageTaken << " damage! ";
}
//--------------- Tanjiro ---------------\\

Tanjiro::Tanjiro(string n, int atk, int hp, int def, int pt)
{
	name = n;
	attack = atk;
	defence = def;
	health = hp;
	points = pt;
	exp = 0;
	level = 1;
	techName = "\0";
	foundKey = false;
	rage = false;
	breathingTech = false;
	teammateCount = 0;
	playerCount++;
	for (int i = 0; i < 4; i++)
		teammates[i] = nullptr;
}

Tanjiro::Tanjiro(const Tanjiro& other) : Player(other)
{
	rage = other.rage;
	breathingTech = other.breathingTech;
	type = other.type;
}

Teammates& Tanjiro::getTeammates(int i)
{
	return *teammates[i];
}
string Tanjiro::getName() const { return name; }
int Tanjiro::getAttack() const { return attack; }
void Tanjiro::setAttack(int newAttack)
{
	attack = newAttack;
	if (rage)
		attack += 15;
	if (breathingTech)
		attack += 30;
}
int Tanjiro::getDefence() const { return defence; }
void Tanjiro::setDefence(int newDefence)
{
	defence = newDefence;
	if (breathingTech)
	{
		if (type == HlpObjects::FOR_DEMONS::WIND_BREATHING)
			defence += 25;
		else
			defence += 10;
	}
}
int Tanjiro::getHealth() const { return health; }
int Tanjiro::getPoints() const { return points; }
int Tanjiro::getExp() const { return exp; }
int Tanjiro::getLevel() const { return level; }
bool Tanjiro::hasFoundKey() const { return foundKey; }
void Tanjiro::setHealth(int health) { this->health = health; }
void Tanjiro::setPoints(int points) { this->points = points; }
void Tanjiro::setExp(int exp) { this->exp = exp; }
void Tanjiro::setLevel(int level) { this->level = level; }
void Tanjiro::setFoundKey(bool foundKey) { this->foundKey = foundKey; }
void Tanjiro::victoryDialogue()
{
	cout << "Tanjiro: 'I will protect everyone!'\n";
}
void Tanjiro::setTechnique(HlpObjects::FOR_DEMONS tp)
{
	type = tp;
	breathingTech = true;
	switch (tp)
	{
	case HlpObjects::FOR_DEMONS::SUN_BREATHING:
		techName = "Sun Breathing";
		break;
	case HlpObjects::FOR_DEMONS::THUNDER_BREATHING:
		techName = "Thunder Breathing";
		break;
	case HlpObjects::FOR_DEMONS::SWORD:
		techName = "Sword Breathing";
		break;
	case HlpObjects::FOR_DEMONS::HEAL_BREATHING:
		techName = "Heal Breathing";
		break;
	case HlpObjects::FOR_DEMONS::WIND_BREATHING:
		techName = "Wind Breathing";
		break;
	default:
		techName = "\0";
	}
}

void Tanjiro::takeDamage(int dmg)
{
	bool isFocused = false;
	if (rand() % 100 < 30)
		isFocused = true;

	if (isFocused)
	{
		dmg /= 2;
		cout << name << " Defense using Water Breathing! Damage halved!\n";
	}

	bool isCritical = false;
	if (rand() % 100 > 10)
		isCritical = true;

	if (isCritical)
	{
		dmg *= 2;
		cout << "Hinokami Kagura! CRITICAL HIT!\n";
	}

	int damageTaken = dmg - (defence / 2);
	if (damageTaken <= 0)
		damageTaken = 10;

	health -= damageTaken;
	if (health < 0)
		health = 0;

	cout << name << " took " << damageTaken << " damage! ";
}

//--------------- Zenitsu ---------------\\

Zenitsu::Zenitsu(string n, int atk, int hp, int def, int pt)
{
	name = n;
	attack = atk;
	defence = def;
	health = hp;
	points = pt;
	exp = 0;
	level = 1;
	techName = "\0";
	foundKey = false;
	isSleep = false;
	breathingTech = false;
	teammateCount = 0;
	playerCount++;
	for (int i = 0; i < 4; i++)
		teammates[i] = nullptr;
}

Zenitsu::Zenitsu(const Zenitsu& other) : Player(other)
{
	isSleep = other.isSleep;
	breathingTech = other.breathingTech;
	type = other.type;
}

string Zenitsu::getName() const { return name; }
int Zenitsu::getAttack() const { return attack; }
void Zenitsu::setAttack(int newAttack)
{
	attack = newAttack;
	if (isSleep)
		attack *= 2;
	if (breathingTech)
		attack += 30;
}
Teammates& Zenitsu::getTeammates(int i)
{
	return *teammates[i];
}
int Zenitsu::getDefence() const { return defence; }
void Zenitsu::setDefence(int newDefence)
{
	defence = newDefence;
	if (isSleep)
		defence = 0;
	else if (breathingTech && type == HlpObjects::FOR_DEMONS::THUNDER_BREATHING)
		defence += 5;
}
int Zenitsu::getHealth() const { return health; }
int Zenitsu::getPoints() const { return points; }
int Zenitsu::getExp() const { return exp; }
int Zenitsu::getLevel() const { return level; }
bool Zenitsu::hasFoundKey() const { return foundKey; }
void Zenitsu::setHealth(int health) { this->health = health; }
void Zenitsu::setPoints(int points) { this->points = points; }
void Zenitsu::setExp(int exp) { this->exp = exp; }
void Zenitsu::setLevel(int level) { this->level = level; }
void Zenitsu::setFoundKey(bool foundKey) { this->foundKey = foundKey; }
void Zenitsu::victoryDialogue()
{
	cout << "Zenitsu: 'I did it while sleeping!'\n";
}
void Zenitsu::setTechnique(HlpObjects::FOR_DEMONS tp)
{
	type = tp;
	breathingTech = true;
	switch (tp)
	{
	case HlpObjects::FOR_DEMONS::SUN_BREATHING:
		techName = "Sun Breathing";
		break;
	case HlpObjects::FOR_DEMONS::THUNDER_BREATHING:
		techName = "Thunder Breathing";
		break;
	case HlpObjects::FOR_DEMONS::SWORD:
		techName = "Sword Breathing";
		break;
	case HlpObjects::FOR_DEMONS::HEAL_BREATHING:
		techName = "Heal Breathing";
		break;
	case HlpObjects::FOR_DEMONS::WIND_BREATHING:
		techName = "Wind Breathing";
		break;
	default:
		techName = "\0";
	}
}
void Zenitsu::takeDamage(int dmg)
{
	bool isSleeping = false;
	if (rand() % 100 < 20)
		isSleeping = true;

	if (isSleeping)
	{
		cout << name << " dodged in his sleep! No damage taken!\n";
		return;
	}

	bool isCritical = false;
	if (rand() % 100 > 15)
		isCritical = true;

	if (isCritical)
	{
		dmg *= 2;
		cout << "THUNDER CLAP AND FLASH! CRITICAL HIT!\n";
	}

	int damageTaken = dmg - (defence / 3);
	if (damageTaken <= 0)
	{
		damageTaken = 10;
	}

	health -= damageTaken;
	if (health < 0)
	{
		health = 0;
	}

	cout << name << " took " << damageTaken << " damage! ";
}

//--------------- Yuta ---------------\\

Yuta::Yuta(string n, int atk, int hp, int def, int pt)
{
	name = n;
	attack = atk;
	defence = def;
	health = hp;
	points = pt;
	exp = 0;
	level = 1;
	techName = "\0";
	foundKey = false;
	domainExpansion = false;
	teammateCount = 0;
	playerCount++;
	for (int i = 0; i < 4; i++)
		teammates[i] = nullptr;
}

Teammates& Yuta::getTeammates(int i)
{
	return *teammates[i];
}
Yuta::Yuta(const Yuta& p) : Player(p)
{
	domainExpansion = p.domainExpansion;
}

string Yuta::getName() const { return name; }
int Yuta::getAttack() const { return attack; }
void Yuta::setAttack(int newAttack)
{
	attack = newAttack;
	if (domainExpansion)
		attack += 30;
}
int Yuta::getDefence() const { return defence; }
void Yuta::setDefence(int def)
{
	defence = def;
	if (techName == "Reverse Curse Technique")
	{
		defence += 20;
		health += 30;
	}
	else if (domainExpansion)
		defence += 50;
}
int Yuta::getHealth() const { return health; }
int Yuta::getPoints() const { return points; }
int Yuta::getExp() const { return exp; }
int Yuta::getLevel() const { return level; }
bool Yuta::hasFoundKey() const { return foundKey; }
void Yuta::setHealth(int hp) { health = hp; }
void Yuta::setPoints(int pt) { points = pt; }
void Yuta::setExp(int exp) { this->exp = exp; }
void Yuta::setLevel(int lvl) { level = lvl; }
void Yuta::setFoundKey(bool key) { foundKey = key; }
void Yuta::victoryDialogue()
{
	cout << "Yuta: 'I'll protect my friends! Thanks Rika!!'\n";
}
void Yuta::setTechnique(HlpObjects::FOR_JUJUTSU tech)
{
	switch (tech)
	{
	case HlpObjects::FOR_JUJUTSU::SIX_EYES:
		techName = "Six Eyes";
		break;
	case HlpObjects::FOR_JUJUTSU::REVERSE_CURSE_TECHNIQUE:
		techName = "Reverse Curse Technique";
		break;
	case HlpObjects::FOR_JUJUTSU::SPECIAL_GRADE_ITEM:
		techName = "Special Grade Item";
		break;
	case HlpObjects::FOR_JUJUTSU::DOMAIN_EXPANSION:
		techName = "Domain Expansion";
		domainExpansion = true;
		break;
	case HlpObjects::FOR_JUJUTSU::LIMITLESS_TECHNIQUE:
		techName = "Limitless Technique";
		break;
	default:
		techName = "\0";
	}
}
void Yuta::takeDamage(int dmg)
{
	bool critical = false;
	if (rand() % 100<20)
		critical = true;

	if (critical)
	{
		dmg *= 2;
		cout << name << "Took CRITICAL HIT!\n";
	}

	int damage = dmg - (defence / 2);
	if (damage <= 0)
	{
		damage = 10;
	}

	if (health < 50 && rand() % 4 == 0)
	{
		damage /= 2;
		cout << "Rika protected " << name << "! Damaged Reduced to half!\n";
	}

	health -= damage;
	if (health < 0)
	{
		health = 0;
	}

	cout << name << " took " << damage << " damage!\n";
}