// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;

int LinearSearch(const std::vector<int>& numbers, int numberToFind)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numberToFind == numbers[i])
        {
            return i;
        }
    }
    return NOT_FOUND;
}

void PrintGrades(const std::map<std::string,double>& grades)
{
    std::cout << "\nPG2 2507\n";
    for (auto& [student, grade] : grades)
    {
        std::cout << std::setw(10) << std::left << student;
        Console::SetForegroundColor(
            //ternary operator
            (grade < 59.5) ? ConsoleColor::Red : 
            (grade < 69.5) ? ConsoleColor::Yellow : 
            (grade < 79.5) ? ConsoleColor::Cyan : 
            (grade < 89.5) ? ConsoleColor::Magenta : 
            ConsoleColor::Green
        );
        std::cout << std::right << std::setw(7) << grade << "\n";
        Console::Reset();
    }
    std::cout << "\n\n";
}
int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == NOT_FOUND)
    {
        std::cout << searchNumber << " was not found.\n";
    }
    else
    {
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";
    }



    //menu map. stores the name + price
    //name is the key (std::string)
    //price is the value (float)
    std::map<std::string, float> menu;

    //2 ways to add items to a map
    // adds a key-value pair to the map
    //  1) (easy way) map[key] = value;

    menu["bagel"] = 5.99f;
    menu["eggs"] = 3.99f;
    menu["belgian waffles"] = 11.99f;
    menu["belgian waffles"] = 12.99f;//overwrites the value

    //  2) (the hard way) map.insert(pair object);
    std::pair<std::string, float> menuPair =
        std::make_pair("pancakes", 9.99f);
    auto result =  menu.insert(menuPair);
    //pair objects have 2 parts: first and second
    if (result.second)
        std::cout << "Item was inserted.\n";
    else
        std::cout << "Item was NOT inserted.\n";
    menuPair.second = 10.99f;
    result = menu.insert(menuPair);//does NOT overwrite the value
    if (result.second)
        std::cout << "Item was inserted.\n";
    else
        std::cout << "Item was NOT inserted.\n";


    //range-based for
    for (auto& [itemName,itemPrice] : menu)
    {
        std::cout << itemName << "  " << itemPrice << "\n";
    }

    //iterator loop
    for (auto i = menu.begin(); i != menu.end(); i++)
    {
        std::cout << (*i).first << " " << i->second << "\n";
    }

    std::cout << menu["belgian waffles"] << "\n";
    //use the find(key)
    std::string itemToFind = "belgian waffles";
    auto foundIterator = menu.find(itemToFind);//uses binary search internally
    if (foundIterator == menu.end())
    {
        std::cout << itemToFind << " is not on the menu. Try McDonald's.\n";
    }
    else
    {
        float original = foundIterator->second;
        foundIterator->second *= 1.05;
        std::cout << itemToFind << " used to costs " << original << ".";
        std::cout << " Now it costs " << foundIterator->second << "!! Thanks Putin.\n";
    }
    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */

    std::vector<std::string> students = {
        "Garrett", "Benjamin", "Eric", "Tammi", "Zachary", "Dante", "Alan", "Richard", "Thomas"
    };
    srand(time(NULL));
    std::map<std::string, double> grades;
    for (auto& name : students)
    {
        grades[name] = rand() % 10001 / 100.0;
    }

    do
    {
        PrintGrades(grades);
        std::string student = Input::GetString("Student to curve: ");
        if (student.empty()) break;

        auto foundStudent = grades.find(student);
        if (foundStudent == grades.end())
        {
            std::cout << student << " is not in PG2.\n";
        }
        else
        {
            foundStudent->second = std::min(100.0, foundStudent->second + 5);
            std::cout << student << " now has a grade of " << foundStudent->second << "\n";
        }
    } while (true);


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an existing value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}