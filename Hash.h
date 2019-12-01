#pragma once
#ifndef Hash_h
#define Hash_h
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;
class hash1 {
private:
	static const int tableSize = 4;

	struct item 
	{
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hash1();
	int Hash(string key);

	void AddItem(string name, string drink);
	int NumberOfItemsinIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

};



#endif // !Hash_h
