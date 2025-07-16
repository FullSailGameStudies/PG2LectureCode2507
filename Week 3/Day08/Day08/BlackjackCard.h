#pragma once
#include "..\..\Day07\Day07\Card.h"

class BlackjackCard : public Card
{
public:
	BlackjackCard(const std::string& face, CardSuit suit) :
		Card(face,suit)
	{	}

	int Value() const override;

private:
};

