#include "Ghost.h"
#include <iostream>

void Ghost::WhoAmI()
{
	std::cout << name_ << "\n";
}

//prefer to use the member initialization list
// runs before the { } code
Ghost::Ghost(const std::string& name, ConsoleColor clr) :
	//field(parameter)
	name_(name),
	color_(clr)
{
}
