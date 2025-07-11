// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <Console.h>
#include <Input.h>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

void PrintGrades(const std::string& title, const std::map<std::string, double>& grades)
{
    std::cout << "\n" << title << "\n";
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
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasBackpack;
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasBackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasBackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasBackpack.find(Weapon::Axe);
    if (found != dorasBackpack.end())
    {
        dorasBackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                    if not found print an error message
                    else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = rand() % 101;
    grades["Dick"] = rand() % 101;
    grades["Diana"] = rand() % 101;
    grades["Alfred"] = rand() % 101;
    grades["Clark"] = rand() % 101;
    grades["Arthur"] = rand() % 101;
    grades["Barry"] = rand() % 101;

    do
    {
        PrintGrades("DCU", grades);

        std::string name = Input::GetString("Name of student to drop: ");
        if (name.empty()) break;

        auto foundStudent = grades.find(name);
        if (foundStudent != grades.end())
        {
            std::cout << name << " had a grade of " << foundStudent->second << ". Dropping student.\n";
            grades.erase(foundStudent);
        }
        else
        {
            std::cout << name << " was not enrolled. Might I suggest dropping Arthur.\n";
        }
    } while (true);

}