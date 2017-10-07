#include <stdio.h>
#include "cardManager.h"
int main(int argc, char *argv[]) {

	CardManager cardman;
	cardman.sortManager(argv[1],argv[2],argv[3],argv[4]);
	//std::vector<std::shared_ptr<CardInfo>> vect(&cardman.deck[0], &cardman.deck[9]);
	//cardman.mergeSort(cardman.deck,0,9999);
	/*cardman.insertionSort("d");
	std::stringstream iss;
	std::string str;*/


	return 0;
}