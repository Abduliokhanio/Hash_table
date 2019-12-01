#include <iostream>
#include <cstdlib>
#include <string>
#include "Hash.h"
using namespace std;

string name = "";

int main()
{
	hash1 Hashy;
	
	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothie");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

/*Hashy.PrintItemsInIndex(2);
	Hashy.PrintTable();*/
	
/*
	int index;
	hash1 hashy;

	index = hashy.Hash("Paula");
	cout << "index = " << index << endl;
	*/
	
/*
//searching function
		while (name != "exit")
		{
			cout << "Search for ";
			cin >> name;

			if (name != "exit")
			{
				Hashy.FindDrink(name);
			}

			
		

		else if (User_answer == 2)
		{
			//removing function
			while (name != "exit")
			{
				cout << "Remove: ";
				cin >> name;
				if (name != "exit")
				{
					Hashy.RemoveItem(name);
				}
				//Hashy.PrintTable();
				Hashy.PrintItemsInIndex(2);
			}
		}*/

	Hashy.PrintTable();
	return 0;
	
}










