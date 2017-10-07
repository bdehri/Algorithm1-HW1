#pragma once
#include <string>
#include <iostream>

class CardInfo
{
public:
	CardInfo(std::string name, std::string Class, std::string rarity, std::string set, std::string type, int cost);
	~CardInfo();
	std::string name, Class, rarity, set, type ;
	int cost ; 
};

