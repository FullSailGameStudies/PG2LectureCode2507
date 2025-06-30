#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	//declaration in the header
	void AddMenuItem(std::string menuItem);

	void ShowMenu();

private:
	std::vector<std::string> menuItems;

};

