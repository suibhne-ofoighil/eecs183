#include "Floor.h"

using namespace std;

int Floor::tick(int currentTime) {
    //keep track of number of exploded
    int count = 0;
    //store in array
    int explodedPeople[numPeople];
    
    //iterate through people on the floor
    for (int i = 0; i < numPeople; ++i)
    {
        //if people explode when ticked:
        if (people[i].tick(currentTime))
        {
            //add them to exploded array
            explodedPeople[count] = i;
            ++count;
        }
    }
    //remove people in exploded array
    removePeople(explodedPeople, count);
    //return number of people exploded
    return count;
}

void Floor::addPerson(Person p, int request) {
    //add person if there is room on floor
    if (numPeople < MAX_PEOPLE_PER_FLOOR)
    {
        people[numPeople] = p;
        ++numPeople;
        
        //change request accordingly
        if (request > 0)
        {
            hasUpRequest = true;
        }
        else if (request < 0)
        {
            hasDownRequest = true;
        }
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR],
                         int numPeopleToRemove) {
    //iterate through indices to remove...
    for (int i = 0; i < numPeopleToRemove; ++i)
    {
        //zero out all people that need to be removed.
        int indexToRemove = indicesToRemove[i];
        people[indexToRemove] = Person();
        --numPeople;
    }
    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i)
    {
        //iterate through array again, if it is a Person()..
        if (getPersonByIndex(i).getTurn() == 0 and
            getPersonByIndex(i).getCurrentFloor() == 0 and
            getPersonByIndex(i).getTargetFloor() == 0 and
            getPersonByIndex(i).getAngerLevel() == 0)
        {
            //look at the remainding ones in front.
            for (int j = i; j < MAX_PEOPLE_PER_FLOOR; ++j)
            {
                //if is not a person...
                if(!(getPersonByIndex(j).getTurn() == 0 and
                   getPersonByIndex(j).getCurrentFloor() == 0 and
                   getPersonByIndex(j).getTargetFloor() == 0 and
                   getPersonByIndex(j).getAngerLevel() == 0))
                {
                    //switch the spots...
                    people[i] = people[j];
                    people[j] = Person();
                    //stop loop
                    break;
                }
            }
        }
    }
    resetRequests();
}

void Floor::resetRequests() {
    hasUpRequest = false;
    hasDownRequest = false;
    //set current floor
    int currentFloor = people[0].getCurrentFloor();
    //iterate through people and see if there
    for (int i = 0; i < numPeople; ++i)
    {
        if (people[i].getTargetFloor() - currentFloor > 0)
        {
            hasUpRequest = true;
        }
        else if (people[i].getTargetFloor() - currentFloor < 0)
        {
            hasDownRequest = true;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i){
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " O   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "-|-  ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " |   ";
	}
	outs << endl << "              ";
	for (int i = 0; i < numPeople; ++i) {
		outs << "/ \\  ";
	}
	outs << endl << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << i << "   ";
	}
	outs << endl << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i) {
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
	return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
