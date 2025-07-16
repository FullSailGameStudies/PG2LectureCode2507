#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
	int val = 0;
	if (Face() == "A") val = 1;
	else if (face_ == "J" || face_ == "Q" || face_ == "K") 
		val = 10;
	else val = std::stoi(face_);
	return val;
}
