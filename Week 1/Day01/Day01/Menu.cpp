#include "Menu.h"
#include <iostream>
#include <Console.h>

//method definitions go here
//do NOT forget to add the "ClassName::" to the front of the method name
void Menu::AddMenuItem(std::string menuItem)
{
	//code for the method
	menuItems.push_back(menuItem);
}

void Menu::ShowMenu()
{
	std::cout << "\n\nPG2 Cafe\n";
	for (int i = 0; i < menuItems.size(); i++)
	{
		//use the indexer to access and print the items
		std::string item = menuItems[i];
		int itemSize = item.size();
		std::cout << menuItems[i] << "\n";
	}
	//range-based for loop (foreach)
	for (std::string& item : menuItems)
	{
		std::cout << item << "\n";
	}

	//an iterator is an OBJECT that knows how to move
	// through a collection
	// it "points" into the collection at one item
	// 0 is the first index
	// .begin() is the iterator to the first item
	// end() is the iterator to the item AFTER the last item??????????
	// end() - 1 is the iterator to the last item
	// size()-1 is the last index in any vector
	// size() - total # of items
	auto iterator = menuItems.begin();
	menuItems.erase(menuItems.begin() + 2);

	for (auto i = menuItems.begin(); i != menuItems.end(); i++)
	{
		//use *i to access the item it points to
		std::cout << *i << "\n";
	}
}
