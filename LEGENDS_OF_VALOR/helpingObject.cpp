#include<iostream>
#include<string>
#include"Classes.h"
using namespace std;

//--------------- Wild Forest Objetcs ---------------\\

ObjectsForWild::ObjectsForWild(HlpObjects::FOR_WILD type, int atk, int def, int price, int recover)
{
	attack = atk;
	defence = def;
	this->price = price;
	recovery = recover;
	switch (type)
	{
	case HlpObjects::FOR_WILD::CROSSBOW:
		name = "Crossbow";
		break;
	case HlpObjects::FOR_WILD::DAGGER:
		name = "Dagger";
		break;
	case HlpObjects::FOR_WILD::FIRST_AID:
		name = "First Aid Kit";
		break;
	case HlpObjects::FOR_WILD::SHIELD:
		name = "Shield";
		break;
	case HlpObjects::FOR_WILD::GUN:
		name = "ShotGun";
		break;
	default:
		cerr << "Invalid Type!\n";
		name = "\0";
	}
}

int ObjectsForWild::getAttack() { return attack; }

int ObjectsForWild::getDefence() { return defence; }

int ObjectsForWild::getRecovery() { return recovery; }

string ObjectsForWild::getName() { return name; }

int ObjectsForWild::getPrice() { return price; }

//--------------- Demon Village Objetcs ---------------\\

ObjectsForDemons::ObjectsForDemons(HlpObjects::FOR_DEMONS type, int atk, int def, int price, int recover)
{
	this->type = type;
	attack = atk;
	defence = def;
	this->price = price;
	recovery = recover;
	switch (type)
	{
	case HlpObjects::FOR_DEMONS::SUN_BREATHING:
		name = "Sun Breathing Techinque";
		break;
	case HlpObjects::FOR_DEMONS::THUNDER_BREATHING:
		name = "Thunder Breathing Techinque";
		break;
	case HlpObjects::FOR_DEMONS::SWORD:
		name = "Demon Slayer Techinque";
		break;
	case HlpObjects::FOR_DEMONS::HEAL_BREATHING:
		name = "Healing Breathing Techinque";
		break;
	case HlpObjects::FOR_DEMONS::WIND_BREATHING:
		name = "Wind Breathing Techinque";
		break;
	default:
		cerr << "Invalid Type!\n";
		name = "\0";
	}
}

int ObjectsForDemons::getAttack() { return attack; }

int ObjectsForDemons::getDefence() { return defence; }

int ObjectsForDemons::getRecovery() { return recovery; }

string ObjectsForDemons::getName() { return name; }

int ObjectsForDemons::getPrice() { return price; }

//--------------- Curse House Objetcs ---------------\\

ObjectsForCurses::ObjectsForCurses(HlpObjects::FOR_CURSES type, int atk, int def, int price, int recover)
{
	this->type = type;
	attack = atk;
	defence = def;
	this->price = price;
	recovery = recover;
	switch (type)
	{
	case HlpObjects::FOR_CURSES::CURSE_SPEACH:
		name = "Curse Speech Amplifier";
		break;
	case HlpObjects::FOR_CURSES::MAGIC_SPELL:
		name = "Magic Spell";
		break;
	case HlpObjects::FOR_CURSES::HEALING_SPELL:
		name = "Healing Spell";
		break;
	case HlpObjects::FOR_CURSES::KILLING_SPELL:
		name = "Killing Spell";
		break;
	case HlpObjects::FOR_CURSES::INVISIBLE_SPELL:
		name = "Invisibility Spell";
		break;
	default:
		cerr << "Invalid Type!\n";
		name = "\0";
	}
}

int ObjectsForCurses::getAttack() { return attack; }

int ObjectsForCurses::getDefence() { return defence; }

int ObjectsForCurses::getRecovery() { return recovery; }

string ObjectsForCurses::getName() { return name; }

int ObjectsForCurses::getPrice() { return price; }

//--------------- JJK World Objetcs ---------------\\

ObjectsForJujutsu::ObjectsForJujutsu(HlpObjects::FOR_JUJUTSU type, int atk, int def, int price, int recover) {
	this->type = type;
	attack = atk;
	defence = def;
	this->price = price;
	recovery = recover;
	switch (type)
	{
	case HlpObjects::FOR_JUJUTSU::LIMITLESS_TECHNIQUE:
		name = "Limitless Technique";
		break;
	case HlpObjects::FOR_JUJUTSU::REVERSE_CURSE_TECHNIQUE:
		name = "Reverse Curse Technique";
		break;
	case HlpObjects::FOR_JUJUTSU::SIX_EYES:
		name = "Six Eyes Technique";
		break;
	case HlpObjects::FOR_JUJUTSU::SPECIAL_GRADE_ITEM:
		name = "Special Grade Sword";
		break;
	case HlpObjects::FOR_JUJUTSU::DOMAIN_EXPANSION:
		name = "Domain Expansion";
		break;
	default:
		cerr << "Invalid Type!\n";
		name = "\0";
	}
}

int ObjectsForJujutsu::getAttack() { return attack; }

int ObjectsForJujutsu::getDefence() { return defence; }

int ObjectsForJujutsu::getRecovery() { return recovery; }

string ObjectsForJujutsu::getName() { return name; }

int ObjectsForJujutsu::getPrice() { return price; }