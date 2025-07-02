#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	void GetGrades(std::vector<float>& courseGrades);

	const std::string& GetName() const;
	void SetName(const std::string& newName);

	void PrintGrades(const std::vector<float>& gradesToPrint) const;

	void EraseGrades(std::vector<float>& grades, float minGrade = 59.5) const;
private:
	std::string name;
};

