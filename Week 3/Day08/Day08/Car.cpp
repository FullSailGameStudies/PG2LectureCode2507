#include "Car.h"



//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


//non-static methods
//there is a 'hidden' parameter called this
//it is a POINTER to the object that the method was called on
//can access BOTH non-static AND static members
std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}
