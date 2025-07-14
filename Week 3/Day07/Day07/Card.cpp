#include "Card.h"
#include <iostream>

int Card::Value() const
{
	int val = 0;
	if (face_ == "A") val = 1;
	else if (face_ == "J") val = 11;
	else if (face_ == "Q") val = 12;
	else if (face_ == "K") val = 13;
	else val = std::stoi(face_);
	return val;
}

void Card::Print() const
{
	std::cout << face_ << " " << suit_ << " " << Value();
}
