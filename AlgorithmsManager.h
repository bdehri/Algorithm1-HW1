#pragma once

#include "cardInfo.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

typedef std::unique_ptr<CardInfo> CardPointer;
typedef std::vector<CardPointer> DeckVector;

class AlgorithmsManager
{
public:
	AlgorithmsManager();
	~AlgorithmsManager();

};

