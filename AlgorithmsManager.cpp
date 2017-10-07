#include "AlgorithmsManager.h"



AlgorithmsManager::AlgorithmsManager()
{
}


AlgorithmsManager::~AlgorithmsManager()
{
}

void AlgorithmsManager::mergeSort(DeckVector& sortVector, int lowIndice, int highIndice, std::string type) {
	if (lowIndice < highIndice) {
		int middle = floor((highIndice + lowIndice) / 2);
		mergeSort(sortVector, lowIndice, middle,type);
		mergeSort(sortVector, middle + 1, highIndice,type);
		merge(sortVector, lowIndice, middle, highIndice, type);
	}

}

void AlgorithmsManager::merge(DeckVector& sortVector, int lowIndice, int middle, int highIndice, std::string type) {
	int n1 = middle - lowIndice + 1;
	int n2 = highIndice - middle;

	DeckVector leftVec(n1);
	DeckVector rightVec(n2);
	int index = 0;
	for (int i = 0; i < n1; i++)
	{
		index = lowIndice + i;
		leftVec[i] = std::move(sortVector[index]);
	}
	for (int j = 0; j < n2; j++)
	{
		index = middle + j + 1;
		rightVec[j] = std::move(sortVector[index]);
	}
	int i = 0;
	int j = 0;
	for (auto k = lowIndice; k <= highIndice; k++)
	{
		if (j < n2 && i < n1) {
			if (type == "full") {
				if (leftVec[i]->Class < rightVec[j]->Class)
				{
					sortVector[k] = std::move(leftVec[i]);
					i = i + 1;
				}
				else if (leftVec[i]->Class == rightVec[j]->Class) { //if class equals sort according to cost
					if (leftVec[i]->cost < rightVec[j]->cost) {
						sortVector[k] = std::move(leftVec[i]);
						i = i + 1;
					}
					else if (leftVec[i]->cost == rightVec[j]->cost) { //if cost equals sort according to name
						if (leftVec[i]->name <= rightVec[j]->name) {
							sortVector[k] = std::move(leftVec[i]);
							i = i + 1;
						}
						else {
							sortVector[k] = std::move(rightVec[j]);
							j++;
						}
					}
					else
					{
						sortVector[k] = std::move(rightVec[j]);
						j++;
					}
				}
				else {
					sortVector[k] = std::move(rightVec[j]);
					j++;
				}
			}
			else if (type == "filter")
			{
				if (leftVec[i]->type <= rightVec[j]->type) //sort according to type
				{
					sortVector[k] = std::move(leftVec[i]);
					i = i + 1;
				}
				else {
					sortVector[k] = std::move(rightVec[j]);
					j++;
				}
			}
		}
		else if (j < n2) // move rest of the vectors
		{
			sortVector[k] = std::move(rightVec[j]);
			j++;
		}
		else if (i < n1)
		{
			sortVector[k] = std::move(leftVec[i]);
			i = i + 1;
		}

	}
}

void AlgorithmsManager::insertionSort(DeckVector& sortVector, const std::string type) {

	for (auto j = 1; j < sortVector.size(); j++)
	{
		CardPointer keyNode = std::move(sortVector[j]);
		int i = j - 1;
		while (i >= 0)
		{
			if (type == "full") {
				if (sortVector[i]->Class > keyNode->Class)
				{
					sortVector[i + 1] = std::move(sortVector[i]);
					i = i - 1;
				}
				else if (sortVector[i]->Class == keyNode->Class) {
					if (sortVector[i]->cost > keyNode->cost) {
						sortVector[i + 1] = std::move(sortVector[i]);
						i = i - 1;
					}
					else if (sortVector[i]->cost == keyNode->cost) {
						if (sortVector[i]->name > keyNode->name) {
							sortVector[i + 1] = std::move(sortVector[i]);
							i = i - 1;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			else if (type == "filter") {
				if (sortVector[i]->type > keyNode->type)
				{
					sortVector[i + 1] = std::move(sortVector[i]);
					i = i - 1;
				}
				else {
					break;
				}
			}
		}
		sortVector[i + 1] = std::move(keyNode);
	}
}
