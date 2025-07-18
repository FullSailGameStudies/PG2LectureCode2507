﻿#include <iostream>
#include <string>
#include <vector>
#include <Input.h>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    //capacity() - length of the internal array
    //size() - # of items in the array
    //size() <= capacity()
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}
//myName is going to be a reference to the variable 
// used then calling the method
//does NOT make a copy
// Copies are "EXPENSIVE" for the runtime
// In general, ALWAYS pass classes by reference
// for types like vector
void GetWhoIAm(std::string& myName)
{
    myName = Input::GetString("Who are you? ");
    //this changes the variable in main
}
void WhoAmI(const std::string& name = "Bats")//name = Alfred
{
    std::cout << name << "\n";
}//name is removed from memory
int main()
{
    int day = 2;
    std::string alfred = "Alfred P.";
    std::string bruce;
    GetWhoIAm(bruce);
    std::string& batman = bruce;
    batman = "";//erased the characters from bruce
    batman = alfred;//copying the characters from alfred to bruce

    std::string myName = "Bruce W.";
    WhoAmI(myName);//pass the variable BY value (COPY)
    WhoAmI();
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.GetGrades(grades);
    std::cout << "\n\nPG2 2507\n";
    for (auto& grade : grades)
    {
        std::cout << grade << "\n";
    }
    std::cout << "\n";

    pg2.SetName("PG2 2507 (July)");
    pg2.PrintGrades(grades);
    pg2.EraseGrades(grades);
    pg2.PrintGrades(grades);


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);//presizes the internal array
    printInfo(highScores);//size: 0  capacity: 0
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}