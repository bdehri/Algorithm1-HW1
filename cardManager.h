#pragma once

#include "cardInfo.h"


#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

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
    void mergeSort(DeckVector& sortVector, int lowIndice, int highIndice, std::string type);
	void insertionSort(DeckVector& sortVector, const std::string type);
	void merge(DeckVector& sortVector, int lowIndice, int middle, int highIndice, std::string type);

};



