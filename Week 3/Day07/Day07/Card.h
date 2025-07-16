#pragma once
#include <string>
enum CardSuit
{
	Hearts,Diamonds,Clubs,Spades
};
class Card
{
public:
	Card(const std::string& face, CardSuit suit)
		: face_(face), suit_(suit)
	{
	}

	virtual int Value() const;
	void Print() const;



	const std::string& Face() const { return face_; }
	void Face(const std::string& face)
	{
		if (not face.empty())//TODO: check that it is a valid face
		{
			face_ = face;
		}
	}

	CardSuit Suit() const { return suit_; }
	void Suit(CardSuit suit)
	{
		if (suit >= Hearts && suit <= Spades)//TODO: check that it is a valid suit
		{
			suit_ = suit;
		}
	}


protected:
	std::string face_;
	CardSuit suit_;


};

