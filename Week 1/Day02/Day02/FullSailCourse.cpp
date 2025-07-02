#include "FullSailCourse.h"
#include <iostream>

void FullSailCourse::GetGrades(std::vector<float>& courseGrades)
{
	for (int i = 0; i < 20; i++)
	{
		courseGrades.push_back(rand() % 10001 / 100.0f);
	}
}

const std::string& FullSailCourse::GetName() const
{
	return name;
}

void FullSailCourse::SetName(const std::string& newName)
{
	name = newName;
}

void FullSailCourse::PrintGrades(const std::vector<float>& gradesToPrint) const
{
	std::cout << "\n" << name << "\n";
	//for (int i = 0; i < gradesToPrint.size(); i++)
	//{
	//	std::cout << gradesToPrint[i] << "\n";
	//}
	for (auto& grade : gradesToPrint)
	{
		std::cout << grade << "\n";
	}
}

void FullSailCourse::EraseGrades(std::vector<float>& grades, float minGrade) const
{
	//1) decrement the index when something is erased
	for (int i = 0; i < grades.size(); i++)
	{
		if (grades[i] < minGrade)
		{
			grades.erase(grades.begin() + i);
			--i;//forces the index to be re-evaluated the next time through the loop
		}
	}
	////2) ONLY increment i when something is NOT erased	
	//for (int i = 0; i < grades.size();)
	//{
	//	if (grades[i] < minGrade)
	//	{
	//		grades.erase(grades.begin() + i);
	//	}
	//	else i++;
	//}
	////3) use a reverse for loop
	//for (int i = grades.size() - 1; i >= 0; i--)
	//{
	//	if (grades[i] < minGrade)
	//	{
	//		grades.erase(grades.begin() + i);
	//	}
	//}
	////4) iterator using the other techniques
	//for (auto i = grades.begin(); i != grades.end();)
	//{
	//	//*i - "dereferencing" the "pointer"
	//	if (*i < minGrade)
	//	{
	//		i = grades.erase(i);
	//	}
	//	else i++;
	//}
	
}
