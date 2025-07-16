#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	void showMe();
	//a pure virtual method
	// this makes Weapon abstract
	// cannot create an instance of Weapon
	virtual int calcDamage() = 0;

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}

	//Weapon operator+(const Weapon& wpn)
	//{
	//	Weapon newWpn(mRange + wpn.mRange, mDamage + wpn.mDamage);
	//	return newWpn;
	//}
};

