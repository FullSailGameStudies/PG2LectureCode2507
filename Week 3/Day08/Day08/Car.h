#pragma once
#include <string>
#include <iostream>

class Car
{
public:
	//Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	//{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{	}
	virtual std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

	//static think 'shared'

	//static methods
	// there is NO 'this' pointer
	// CANNOT access non-static members (fields or methods)
	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

protected:
	int mModelYear;
	std::string mModel;
	std::string mMake;

	int mFuelLevel;
	int mMaxFuelLevel;

	//static data is tied to the class level, not the object level
	//there is only ONE mNumberOfCarsMade
	//example: if we create 100000 car objects, there are
	//   100000 year, make, and model variables
	//   but ONLY 1 mNumberOfCarsMade
	//static data 'lives' in the memory for the whole time
	// the app is running
	static int mNumberOfCarsMade; //shared by ALL cars
private:
};

