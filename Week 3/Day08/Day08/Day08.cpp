// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include <vector>
#include "BlackjackCard.h"

void Counter()
{
	//static variables stay in memory for the lifetime of the app
	static int i = 0;
	std::cout << i << " ";
	i++;
}

void PrintInfo(Car* carToPrint)
{
	//it figures out a RUNTIME which vehicleInformation to call
	std::cout << "Ptr Car:\n" << carToPrint->vehicleInformation() << "\n";
}

int* GetNumber()
{
	int* i = new int(15);
	return i;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	/*
		╔═══════════════╗
		║  Inheritance  ║
		╚═══════════════╝

								╔═════════╗     ╔══════════╗
						 class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)



				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car

	*/
	int num = 5;
	long lNum = num;//implicit cast
	float fNum = 5.3;
	num = (int)fNum;//explicit cast

	Car myRide(2009, "Ford", "Expedition");
	Car otherRide(2025, "Tesla", "CyberTruck");
	std::cout << otherRide.vehicleInformation(  ) << "\n";
	FlyingCar jetsons(2025,"Tesla","CyberPlane", 1000, 0);
	std::cout << jetsons.vehicleInformation() << "\n";
	std::cout << myRide.vehicleInformation() << "\n";
	Car todaysRide = jetsons;//what does this do??? copy ONLY the car parts to todaysRide
	std::cout << todaysRide.vehicleInformation() << "\n";

	// :: - scope resolution operator
	//Car::reporting();

	Car& refCar = jetsons;//what does this do??? 
	//UPCAST. casting from a derived type UP the hierarchy to a base type
	//ALWAYS safe
	//DOWNCASTING casting from a base type DOWN the hierarchy to a derived type.
	//NOT SAFE!!!!
	Car* ptrCar = &jetsons;//cast? 
	//*ptr is called dereferencing
	//ptr-> is also dereferencing
	ptrCar = &myRide;
	std::cout << "Ptr Car:\n" << ptrCar->vehicleInformation() << "\n";
	std::cout << "REF Car:\n" << refCar.vehicleInformation() << "\n";
	int n1 = 5;//4 bytes on the STACK
	int* pN1;//pointers only store memory address. for 64-bit apps, 8 bytes
	pN1 = &n1;//gets the address-of n1 and stores it in pN1
	std::cout << "\npN1 " << *pN1 << "\n";
	int n2 = 2;
	pN1 = &n2;
	std::cout << "\npN1 " << *pN1 << "\n";
	int sum = n1 + n2;
	refCar = todaysRide;//copy todaysRide over jetsons

	//the HEAP (think your laundry pile)
	// ` = new` means HEAP memory
	// every NEW operation needs a corresponding DELETE operation
	{
		int* heapN1 = new int(10);//heapN1 lives on the STACK. int(10) lives on the heap.
		pN1 = heapN1;
		delete heapN1;//free the heap memory when you are done using it

		Car stackCar(2025, "FullSail", "PG2");
		Car* heapCar = new Car(2025, "FullSail", "PG2");
		ptrCar = heapCar;
		delete heapCar;
	}//what happens here? the stack variable is deleted but not the heap. we just leaked memory.
	//too much heap memory leaks causes exceptions. run out of heap memory.

	//use unique_ptr to manage the memory for us
	{
		std::unique_ptr<int> uptrN1 = std::make_unique<int>(10); 
		std::unique_ptr<int> uptrN2 = std::move(uptrN1);//transfers ownership
	}//when uptrN1 goes out of scope, it deletes the memory automatically

	std::vector<Car*> garage;
	garage.push_back(&myRide);
	garage.push_back(&otherRide);
	garage.push_back(&jetsons);
	std::cout << "\nMy Garage\n";
	for (auto& car : garage)
	{
		std::cout << "\n" << car->vehicleInformation() << "\n";
	}

	//std::cout << "Ptr Car:\n" << ptrCar->vehicleInformation() << "\n";
	std::cout << "\npN1 " << *pN1 << "\n";


	//Weapon wpn1(10, 50);
	//Weapon wpn2(20, 75);
	//Weapon wpn3 = wpn1 + wpn2;

	std::cout << "\n\nBlackjack Card\n";
	std::vector<std::string> faces{ "A","2","3","4",
	"5","6","7","8","9","10","J","Q","K" };
	srand(time(NULL));
	BlackjackCard card(
		"Q",//faces[rand() % faces.size()],
		(CardSuit)(rand() % 4));
	card.Print();
	std::cout << "\n\n";

	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

	*/






	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
		╔════════════════════════╗
		║  RUNTIME Polymorphism  ║
		╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

