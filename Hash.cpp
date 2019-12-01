#include <iostream>
#include <cstdlib>
#include <string>
#include "Hash.h"
using namespace std;


hash1::hash1()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i] ->name = "empty";
		HashTable[i] ->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

void hash1::AddItem(string name, string drink)
{
	int index = Hash(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;

	}
}

int hash1::NumberOfItemsinIndex(int index)
{
	int count = 0;
	if (HashTable[index]->name == "empty")
	{
		return count; 
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;

		}
	}
	return count;
}

void hash1::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsinIndex(i);
		cout << "---------------------" << endl;
		cout << "index == " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "Number of items = " << number << endl;
		cout << "---------------------" << endl;

	}
}

void hash1::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index = " << index << " is empty" << endl;
	}
	else
	{
		cout << "index " << index << " contains the following items" << endl;

		while (Ptr != NULL)
		{
			cout << "-----------------------------------------" << endl;
			cout << Ptr->name << endl;
			cout << Ptr->drink << endl;
			cout << "-----------------------------------------" << endl;
			Ptr = Ptr->next;

		}
	}
}

int hash1::Hash(string key)
{
	int hash = 0;
	int index;
	
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) *17;
		//cout << "Hash = " << hash << endl; 
	}
	//cout << endl;

	//----------------------------------------------------------------------------------------
	/*
	cout << "Ascii Values added: " << endl;
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
		cout << "Hash = " << hash << endl;
	}
	cout << endl;
	*/
	//----------------------------------------------------------------------------------------
	/*
	cout << "Ascii Values: " << endl;
	for (int i = 0; i < key.length(); i++)
	{
		cout << "key[" << i << "] = " << (int)key[i] << endl;
	}
	cout << endl;
	*/
	//----------------------------------------------------------------------------------------
	/*cout << key << " Has an Index Values of : " << endl;*/


	index = hash % tableSize;
	
	return index;
}

void hash1::FindDrink(string name)
{
	int index = Hash(name);
	bool foundName = false;
	string drink;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			drink = Ptr->drink;

		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		cout << "Favorite drink == " << drink << endl;
	}
	else
	{
		cout << name << "'s info was not found in the hash table" << endl;
	}

}

void hash1::RemoveItem(string name)
{
	int index = Hash(name);
	item* delPtr;
	item* P1;
	item* P2;

	//Case 0 - bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
	{
		cout << name << " was not found in the hash table";
	}

	//Case 1 - only 1 item contained in the bucket and that item has a matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
	}

	//Case 2 - match is located in the 1st item in the budget but there are more item in the bucket
	else if (HashTable[index]->name == name)
	{
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the hash table" << endl;
	}

	//Case 3 - bucket contains multipe items an the 1st is not a match
	else
	{
		P1 = HashTable[index]->next;
		P2 = HashTable[index];

		while (P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
	//Case 3.1 - no match
		if (P1 == NULL)
		{
			cout << name << " was not found in the hash table" << endl;
		}
	//Case 3.2 - match is found 
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
			cout << name << " was removed from the hash table" << endl;
		}
	}



	


}






