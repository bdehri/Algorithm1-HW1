#include "cardInfo.h"



CardInfo::CardInfo(std::string name , std::string Class , std::string rarity , std::string set , std::string type , int cost)
{
	this->name = name;
	this->Class = Class;
	this->rarity = rarity;
	this->set = set;
	this->type = type;
	this->cost = cost;
}


CardInfo::~CardInfo()
{
}
