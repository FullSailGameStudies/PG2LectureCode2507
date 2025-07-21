// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"
#include "SubTexture.h"
#include <algorithm> 
#include <locale>

bool LoadSubtextures(std::vector<SubTexture>& textures)
{
    bool wasLoaded = false;
    std::string file = "character_robot_sheetHD.csv";
    std::ifstream inFile(file);
    if (inFile.is_open())
    {
        wasLoaded = true;
        std::string textureFile;
        std::getline(inFile, textureFile);

        std::string line;
        char delimiter = '?';
        while (not inFile.eof())
        {
            std::getline(inFile, line);
            std::stringstream lineStream(line);

            SubTexture subTex;
            std::getline(lineStream, subTex.name, delimiter);

            std::string data;
            try
            {
                std::getline(lineStream, data, delimiter);
                subTex.x = std::stoi(data);

                std::getline(lineStream, data, delimiter);
                subTex.y = std::stoi(data);

                std::getline(lineStream, data, delimiter);
                subTex.width = std::stoi(data);

                std::getline(lineStream, data, delimiter);
                subTex.height = std::stoi(data);

                textures.push_back(subTex);
            }
            catch (const std::exception&)
            {
                std::cout << "error parsing file. Data: " << data << "\n";
                wasLoaded = false;
                break;
            }
        }
    }
    else std::cout << file << " could not be opened.\n";

    inFile.close();

    return wasLoaded;
}
bool charComparer(char c1, char c2)
{
    return std::tolower(c1, std::locale()) == std::tolower(c2, std::locale());
}
bool isPrefix(const std::string& prefix, const std::string& word)
{
    return  (std::mismatch(prefix.begin(), prefix.end(),
        word.begin(), word.end(),
        charComparer)).first == prefix.end();
}

void SaveWalkingSubTextures(const std::vector<SubTexture>& subTextures)
{
    std::string file = "walking_sheetHD.csv";
    std::ofstream outFile(file);
    char delimiter = '^';
    if (outFile.is_open())
    {
        bool isFirst = true;
        for (auto& subTexture : subTextures)
        {
            if (not isFirst) outFile << "\n";
            if (isPrefix("walk", subTexture.name))
            {
                outFile << subTexture.name << delimiter;
                outFile << subTexture.x << delimiter;
                outFile << subTexture.y << delimiter;
                outFile << subTexture.width << delimiter;
                outFile << subTexture.height;
                isFirst = false;
            }
        }
    }
    else std::cout << file << " could not be opened.\n";

    outFile.close();

}

/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    std::vector<SubTexture> subTextures;
    if (LoadSubtextures(subTextures))
    {
        for (auto& subTex : subTextures)
        {
            std::cout << "Name: " << subTex.name << "\n\tx: " << subTex.x;
            std::cout << "\n\ty: " << subTex.y << "\n\twidth: " << subTex.width;
            std::cout << "\n\theight: " << subTex.height << "\n";
        }
    }
    else std::cout << "Error reading file.\n";

    SaveWalkingSubTextures(subTextures);

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */
    std::string fileName = "2507.csv";
    std::string path = "C:/temp/2507/";
    std::string fullPath = fileName;
    //will create the file IF the path exists
    //it will NOT create the path
    //1) open the file
    std::ofstream outFile(fullPath);
    char delimiter = '%';
    if (outFile.is_open())
    {
        //2) write the file
        outFile << "Batman rules. Aquaman smells." << delimiter;
        outFile << "F5" << delimiter << true << delimiter << 13.7;
    }
    else std::cout << fullPath << " could not be opened.\n";

    //3) Close the file
    outFile.close();



    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */

    //1) open the file
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //read the data
        std::string line;
        //reads until it encounters a \n OR the end of the file
        std::getline(inFile, line);

        //parse the string to get the data
        std::string data;
        std::stringstream lineStream(line);
        //read until it encounters a % OR the end of the stream
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";

        //try-catch
        try
        {
            //the code that MIGHT throw an exception goes inside the try block
        std::getline(lineStream, data, delimiter);
        int iData = std::stoi(data);
        std::cout << iData << "\n";

        std::getline(lineStream, data, delimiter);
        bool bData = std::stoi(data);// (data == "1") ? true : false;
        std::cout << bData << "\n";

        std::getline(lineStream, data, delimiter);
        float fData = std::stof(data);
        std::cout << fData << "\n";

        }
        //you can have multiple catch blocks
        //order the catch blocks with the more specific exceptions at the top
        //moving down to a move general exception
        catch (const std::exception& ex)
        {
            //the code that HANDLES the exception goes into the catch block
            std::cout << "error parsing the data. check the format.\n" << ex.what() << "\n";
            std::cout << "Data: " << data << "\n";
        }
    }
    else std::cout << fullPath << " could not be opened.\n";

    //3) Close the file
    inFile.close();



    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}