#include "Calculator.h"

int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

int Calculator::Add(int n1, int n2)
{
	return n1 + n2;
}

int Calculator::Subtract(int n1, int n2)
{
	return n1 - n2;
}

int Calculator::Multiply(int n1, int n2)
{
	return n1 * n2;
}

int Calculator::Divide(int n1, int n2)
{
	return n1 / n2;
}

int Calculator::Add(std::vector<int> numbers)
{
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
		sum += numbers[i];
	return sum;
}

int Calculator::Subtract(std::vector<int> numbers)
{
	int diff = numbers[0];
	for (int i = 1; i < numbers.size(); i++)
		diff -= numbers[i];
	return diff;
}

int Calculator::Multiply(std::vector<int> numbers)
{
	int product = 1;
	for (int i = 0; i < numbers.size(); i++)
		product *= numbers[i];
	return product;
}

int Calculator::Divide(std::vector<int> numbers)
{
	int result = numbers[0];
	for (int i = 1; i < numbers.size(); i++)
		result /= numbers[i];
	return result;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}
