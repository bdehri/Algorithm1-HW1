#include "cardManager.h"
#include <math.h>



CardManager::CardManager()
{
}


CardManager::~CardManager()
{
}

void CardManager::readFile(std::string file) {
	int counter = 0;
	std::string line;
	std::ifstream myfile(file);
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))//read file line by line
		{
			std::string name, Class, rarity, set, type;
			int cost;
			std::istringstream iss(line);//stream to split line
			
			std::getline(iss, name, '\t');   // splitting screen by tabs need to find better way
			std::getline(iss, Class, '\t');
			std::getline(iss, rarity, '\t');
			std::getline(iss, set, '\t');
			std::getline(iss, type, '\t');
			iss >> cost;
			
			

			deck.push_back(CardPointer(new CardInfo(name,Class,rarity,set,type,cost))); //storing data as a smart pointer
			counter++;			
		}

	}
	else {
		std::cout << "File could not be opened." << std::endl;
	}
}
void CardManager::writeFile(std::string file) {
	std::string line;
	std::ofstream myfile(file);
	if (myfile.is_open())
	{
		for(auto i = 0 ; i < deck.size() ; i++)//write file line by line
		{
			myfile << deck[i]->name << "\t" << deck[i]->Class << "\t" << deck[i]->rarity << "\t" <<
			deck[i]->set << "\t" << deck[i]->type << "\t" << deck[i]->cost <<"\n";
		}

	}
	else {
		std::cout << "File could not be opened." << std::endl;
	}
}


void CardManager::filterSort(std::string type) {
	if (type == "-i") {
		AlgorithmsManager::insertionSortFilter(deck);
	}
	if (type == "-m") {
		AlgorithmsManager::mergeSortFilter(deck,0,(deck.size()-1));
	}
}

void CardManager::fullSort(std::string type) {
	if (type == "-i") {
		AlgorithmsManager::insertionSortFull(deck);
	}
	if (type == "-m") {
		AlgorithmsManager::mergeSortFull(deck, 0 ,(deck.size() - 1));
	}
}

void CardManager::sortManager(std::string sortingType, std::string algoType, std::string input, std::string output) {
	
	readFile(input);

	std::cout << "I/O finished \n";
	
	auto start = std::chrono::system_clock::now();

	if (sortingType == "-full") {
		fullSort(algoType);
	}
	else if (sortingType == "-filter") {
		filterSort(algoType);
	}
	auto end = std::chrono::system_clock::now();

		/*for (auto x=0;x<deck.size();x++)
	{
		std::cout << deck[x]->name << "\t" << deck[x]->Class << "\t" << deck[x]->rarity << "\t" <<
			deck[x]->set << "\t" << deck[x]->type << "\t" << deck[x]->cost << std::endl;

	}*/

	writeFile(output);		
			
	deck.clear();

	std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 	std::cout << output << std::endl;
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}


