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

	static void mergeSortFilter(DeckVector& sortVector, int lowIndice, int highIndice);
	static void mergeSortFull(DeckVector& sortVector, int lowIndice, int highIndice);
	static void mergeFull(DeckVector& sortVector, int lowIndice, int middle, int highIndice);
	static void mergeFilter(DeckVector& sortVector, int lowIndice, int middle, int highIndice);


	static void insertionSortFull(DeckVector& sortVector );
 	static void insertionSortFilter(DeckVector& sortVector);

};

