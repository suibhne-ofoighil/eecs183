#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    
    //is pass string or not?
    if (commandString.size() > 0)
    {
        stringstream ins;
        ins << commandString;
        
        //variables to parse string
        char moveChar;
        char moveChar2;
        
        //moving through string and parsing it.
        if (ins >> moveChar)
        {
            if (tolower(moveChar) == 'e')
            {
                ins >> elevatorId >> moveChar2;
                if (tolower(moveChar2) == 'p')
                {
                    isPickup = true;
                }
                else if (tolower(moveChar2) == 'f')
                {
                    ins >> targetFloor;
                }
            }
            else if (tolower(moveChar) == 's')
            {
                isSave = true;
            }
            else if (tolower(moveChar) == 'q')
            {
                isQuit = true;
            }
        }
    }
        
    //if commandString.size() <= 0, is pass move
    else
    {
        isPass = true;
    }
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    Elevator elevator = elevators[elevatorId];
    if (isPassMove() || isSaveMove() || isQuitMove())
    {
        return true;
    }
    if (0 <= elevatorId and elevatorId < NUM_ELEVATORS and
        !elevator.isServicing())
    {
        if (isPickupMove())
        {
            return true;
        }
        else if (0 <= targetFloor and targetFloor < NUM_FLOORS and
        elevator.getCurrentFloor() != targetFloor)
        {
            return true;
        }
    }
    return false;
}

void Move::setPeopleToPickup(const string& pickupList,
                             const int currentFloor,
                             const Floor& pickupFloor) {
    int furthestDistance = 0;
    for (int i = 0; i < pickupList.size(); ++i)
    {
        //turn char to int
        int personId = pickupList.at(i) - '0';
        //add int to array
        peopleToPickup[numPeopleToPickup] = personId;
        //incrememnt index
        ++numPeopleToPickup;
        //get persons angerlevel
        int personAnger =
            pickupFloor.getPersonByIndex(personId).getAngerLevel();
        int personSatisfaction = MAX_ANGER - personAnger;
        //add to satisfaction
        totalSatisfaction += personSatisfaction;
        int personTargetFloor =
            pickupFloor.getPersonByIndex(personId).getTargetFloor();
        int distanceFromTargetFloor = abs(currentFloor - personTargetFloor);
        //if distance is longer...
        if (distanceFromTargetFloor > furthestDistance)
        {
            //update furthest distance
            furthestDistance = abs(currentFloor - personTargetFloor);
            //update the target floor
            targetFloor = personTargetFloor;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
