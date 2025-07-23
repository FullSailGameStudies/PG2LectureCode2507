#pragma once
#include <iostream>

class Enclosing 
{
public:
	void DoIt()
	{
		x = 10;
		Nested nest;
		nest.NestedFun(this);
	}
private:
	int x;
	
	/* start of Nested class declaration */ 
	class Nested 
	{
		int y;
	public:
		void NestedFun(Enclosing* e) {
			std::cout << "NESTED: ";
			std::cout << e->x; // works fine: nested class can access 
							   // private members of Enclosing class
			std::cout << "\n\n";
		}
	}; // declaration Nested class ends here


}; // declaration Enclosing class ends here
