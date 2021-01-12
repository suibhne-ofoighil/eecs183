#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string input_string) : Person() {
    stringstream stream;
    stream << input_string;
    char floorChar;
    char targetChar;
    char angerChar;
    stream >> turn;
    stream >> floorChar;
    stream >> currentFloor;
    stream >> targetChar;
    stream >> targetFloor;
    stream >> angerChar;
    stream >> angerLevel;
}

bool Person::tick(int currentTime) {
    if (currentTime % TICKS_PER_ANGER_INCREASE == 0)
    {
        ++angerLevel;
        if (angerLevel >= MAX_ANGER)
        {
            return true;
        }
    }
    return false;
}

void Person::print(ostream &outs) {    
    outs << 'f' << currentFloor << 't' << targetFloor << 'a' << angerLevel;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person() {
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const {
    return turn;
}

int Person::getCurrentFloor() const {    
    return currentFloor;
}

int Person::getTargetFloor() const {    
    return targetFloor;
}

int Person::getAngerLevel() const {    
    return angerLevel;
}

ostream& operator<< (ostream& outs, Person p)
{
    p.print(outs);
    return outs;
}
