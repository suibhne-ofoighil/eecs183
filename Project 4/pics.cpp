/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Suibhne O'Foighil
 * UniqueName: suibhne
 *
 * Code which interfaces with user to draw images from files.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

void printOpener();
void printCloser();
void printMenu();
string openFile(ifstream& ins);
string tolower(string str);
void loadFile(Graphics& drawer);
void writeFile(const Graphics& drawer);

void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
    
    return;
}

void writeFile(const Graphics& drawer)
{
    string fileName;
    cin >> fileName;
    fileName += ".bmp";
    drawer.writeFile(fileName);
    cout << "[Wrote " << fileName << "]" << endl;
}

void loadFile(Graphics& drawer)
{
    ifstream ifs;
    string fileName;
    char shape;
    Line line;
    Circle circle;
    Triangle triangle;
    Rectangle rectangle;
    string remainder;
    
    //initial try to open instructions file
    cin >> fileName;
    fileName += ".txt";
    ifs.open(fileName);
    
    //keep trying until able to open file
    while (ifs.fail())
    {
        ifs.clear();
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        cin >> fileName;
        fileName += ".txt";
        ifs.open(fileName);
    }
    
    //clear drawer
    drawer.clear();
    
    //keep reading till end of file
    while (ifs >> shape)
    {
        if (shape == 'L')
        {
            ifs >> line;
            line.draw(drawer);
        }
        else if (shape == 'C')
        {
            ifs >> circle;
            circle.draw(drawer);
        }
        else if (shape == 'T')
        {
            ifs >> triangle;
            triangle.draw(drawer);
        }
        else if (shape == 'R')
        {
            ifs >> rectangle;
            rectangle.draw(drawer);
        }
        else
        {
            drawer.clear();
            cout << "Error in input file: " << shape;
            getline(ifs, remainder);
            cout << remainder << endl;
        }
    }
    
    //close file
    ifs.close();
    
    //give user feedback
    cout << "[Loaded " << fileName << "]" << endl;
}

string tolower(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
