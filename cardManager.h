#pragma once

#include "cardInfo.h"
#include "AlgorithmsManager.h"


#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <chrono>
#include <ctime>

typedef std::unique_ptr<CardInfo> CardPointer;
typedef std::vector<CardPointer> DeckVector;

class CardManager
{
public:
	CardManager();
	~CardManager();
	
	void sortManager(std::string sortingType, std::string algoType, std::string input, std::string output);

	
private:

	DeckVector deck;

	void readFile(std::string file);
	void filterSort(std::string type);
	void fullSort(std::string type);
	void writeFile(std::string file);

};



