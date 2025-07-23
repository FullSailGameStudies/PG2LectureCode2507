#include "Car.h"
#include <iostream>

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter) const
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

void Car::DeserializeCSV(const std::string& csvLine, char delimiter)
{
	std::stringstream lineStream(csvLine);
	std::string data;

	std::getline(lineStream, data, delimiter);
	try
	{
		mModelYear = std::stoi(data);
	}
	catch (const std::exception&)
	{
		std::cout << data << " could not converted.\n";
		return;
	}

	std::getline(lineStream, mMake, delimiter);
	std::getline(lineStream, mModel, delimiter);
}
