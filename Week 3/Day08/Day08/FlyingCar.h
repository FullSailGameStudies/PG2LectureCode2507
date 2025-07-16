#pragma once
#include "Car.h"
#include "Weapon.h"

//in C++, you can have multiple parents
//FlyingCar is-a Car.  is-a relationship
class FlyingCar : public Car//, public Weapon
{

public:
	//the child ctor MUST call a parent ctor 
	//  so that the parent parts are initialized
	//	the compiler will try to call a default ctor of the parent 
	//  if you do not explicitly call one

	//the order of ctor calls:
	//  base class executes FIRST
	//  derived class next
	FlyingCar(int year, std::string make, std::string model, int maxAlt, int altitude = 0) :
		//call the base ctor here
		Car(year,make,model),//calling a method
		maxAlt_(maxAlt), 
		altitude_(altitude)
	{
		//do NOT duplicate anything that the base ctor does
		std::cout << mModelYear;
	}
	std::string vehicleInformation() override;

	int getAltitude() const {
		return altitude_;
	}

	void setAltitude(int altitude) {
		if (altitude >= 0 and altitude <= maxAlt_)
			altitude_ = altitude;
	}

	int getMaxAltitude() const {
		return maxAlt_;
	}

	void setMaxAltitude(int maxAlt) {
		if (maxAlt >= 0)
			maxAlt_ = maxAlt;
	}

private:
	//has-a relationship.
	//FlyingCar has-a altitude

	//in general, FAVOR has-a (composition, containment) over is-a
	//why? flexibility
	//is-a is part of the build system and can NOT change
	//has-a can change at run-time
	int maxAlt_;
	int altitude_;

};

