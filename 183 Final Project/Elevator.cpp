#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime) {
    if (currentTime % TICKS_PER_ELEVATOR_MOVE == 0 && isServicing())
    {
        // if current floor is below target floor, we move it up one floor
        if (currentFloor - targetFloor < 0)
        {
            ++currentFloor;
        }
        // if it is below, move it down one floor
        else if (currentFloor - targetFloor > 0)
        {
            --currentFloor;
        }
        // after moving, if it has reached target floor, set servicing to false
        if (currentFloor == targetFloor)
        {
            servicing = false;
        }
    }
}

void Elevator::serviceRequest(int floorNum) {
    targetFloor = floorNum;
    servicing = true;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream &outs) {
    outs << currentFloor;
    if (!servicing){
        outs << "w";
    } else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
	targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
	return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
