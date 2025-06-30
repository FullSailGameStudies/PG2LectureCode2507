#pragma once
#include <vector>
class Calculator
{
public:
	//the declaration of the sum method
	int minus(int number1, int number2);

	int Add(int n1, int n2);
	int Subtract(int n1, int n2);
	int Multiply(int n1, int n2);
	int Divide(int n1, int n2);


	int Add(std::vector<int> numbers);
	int Subtract(std::vector<int> numbers);
	int Multiply(std::vector<int> numbers);
	int Divide(std::vector<int> numbers);

	static double mult(double num, double factor);
};

