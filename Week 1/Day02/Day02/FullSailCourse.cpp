#include "FullSailCourse.h"

void FullSailCourse::GetGrades(std::vector<float>& courseGrades)
{
	for (int i = 0; i < 20; i++)
	{
		courseGrades.push_back(rand() % 10001 / 100.0f);
	}
}
