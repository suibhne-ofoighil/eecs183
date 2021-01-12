#include <iostream>
#include <fstream>
#include "Utility.h"
#include "Game.h"

using namespace std;

void person_test();
void elevator_test();
void floor_test();
void move_test();
void test_building();

void start_tests() {
    test_building();
}

void person_test() {
    cout << "testing person():" << endl;
    
    //initialize a person with targetFloor 5, anger 5
    Person p("0f0t5a5");
    
    cout << p << " Expected f0t5a5" << endl;

    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;

    //simulate time being a multiple of TICKS_PER_ANGER_INCREASE
    bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);

    cout << exploded << " Expected 0" << endl;

    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    //simulate time not being a multiple
    p.tick(TICKS_PER_ANGER_INCREASE - 1);

    //no change
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    p.tick(TICKS_PER_ANGER_INCREASE); //7 after

    p.tick(TICKS_PER_ANGER_INCREASE); //8 after

    p.tick(TICKS_PER_ANGER_INCREASE); //9 after

    exploded = p.tick(TICKS_PER_ANGER_INCREASE);

    cout << exploded << " Expected 1" << endl;
    

    cout << p << " Expected f0t5a10" << endl;
    
    Person p1("7f4t8a3");
    
    p1.print(cout);
    cout << " Expected f4t8a3" << endl;
    
    Person p2("89f3a9");
    cout << p2.getTurn() << " Expected 89" << endl;
}

void elevator_test() {
    cout << "testing elevator():" << endl;
    
    Elevator e;
    Elevator ez;
    
    e.serviceRequest(9);
    e.print(cout);
    cout << endl;
    e.tick(1);
    e.print(cout);
    cout << endl;
    e.tick(2);
    e.print(cout);
    cout << endl;
    e.tick(3);
    e.print(cout);
    cout << endl;
    e.tick(4);
    e.print(cout);
    cout << endl;
    e.tick(5);
    e.print(cout);
    cout << endl;
    e.tick(6);
    e.print(cout);
    cout << endl;
    e.tick(7);
    e.print(cout);
    cout << endl;
    e.tick(8);
    e.print(cout);
    cout << endl;
    e.tick(9);
    e.print(cout);
    cout << endl;
    
    e.serviceRequest(3);
    ez.serviceRequest(9);
    e.tick(4);
    e.print(cout);
    cout << endl;
    ez.tick(4);
    ez.print(cout);
    cout << endl;
    e.tick(5);
    e.print(cout);
    cout << endl;
    ez.tick(5);
    ez.print(cout);
    cout << endl;
    e.tick(6);
    e.print(cout);
    cout << endl;
    ez.tick(6);
    ez.print(cout);
    cout << endl;
    e.tick(7);
    e.serviceRequest(9);
    e.print(cout);
    cout << endl;
    ez.tick(7);
    ez.print(cout);
    cout << endl;
    e.tick(8);
    e.print(cout);
    cout << endl;
    ez.tick(8);
    ez.print(cout);
    cout << endl;
    e.tick(9);
    e.print(cout);
    cout << endl;
    ez.tick(9);
    ez.print(cout);
    cout << endl;
    e.tick(9);
    e.print(cout);
    cout << endl;
    ez.tick(9);
    ez.print(cout);
    cout << endl;
    e.tick(9);
    e.print(cout);
    cout << endl;
    ez.tick(9);
    ez.print(cout);
    cout << endl;
    e.tick(9);
    e.print(cout);
    cout << endl;
    ez.tick(9);
    ez.print(cout);
    cout << endl;
}

void floor_test() {
    cout << "testing floor():" << endl;
    
    Person p1("7f4t8a1");
    Person p2("7f4t8a2");
    Person p3("7f4t8a3");
    Person p4("7f4t8a4");
    Person p5("7f4t8a5");
    Person p6("23f8t3a6");
    Person p7("7f4t8a7");
    Person p8("7f4t8a8");
    Person p9("7f4t8a9");
    Person p10("90f1t2a1");
    Person p11("7f4t8a3");
    
    //constructor
    Floor f1;
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 000" << endl;
    
    //addPerson
    f1.addPerson(p1, -8);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 101" << endl;
    f1.addPerson(p2, -1);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 201" << endl;
    f1.addPerson(p3, -4);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 301" << endl;
    f1.addPerson(p4, 5);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 411" << endl;
    f1.addPerson(p5, 100);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 511" << endl;
    f1.addPerson(p6, -123);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 611" << endl;
    f1.addPerson(p7, 3);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 711" << endl;
    f1.addPerson(p8, 1);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 811" << endl;
    f1.addPerson(p9, 1);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 911" << endl;
    f1.addPerson(p10, 1);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 1011" << endl;
    f1.addPerson(p11, 1);
    cout << f1.getNumPeople() <<
            f1.getHasUpRequest() <<
            f1.getHasDownRequest() <<
            " Expecting 1011" << endl;
    
    //remove people
    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i)
    {
        cout << f1.getPersonByIndex(i) << " ";
    }
    cout << endl <<
    f1.getNumPeople() << endl;
    
    int arr[] = {1,3,5,7,9};
    f1.removePeople(arr, 5);

    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i)
    {
        cout << f1.getPersonByIndex(i) << " ";
    }
    cout << endl <<
    f1.getNumPeople() << endl;
    
}

void move_test() {
    cout << "testing move():" << endl;
    
    //pass move
    Move m1("");
    cout << m1.getElevatorId() << " Expecting -1" << endl;
    cout << m1.getTargetFloor() << " Expecting -1" << endl;
    cout << m1.getNumPeopleToPickup() << " Expecting 0" << endl;
    cout << m1.getTotalSatisfaction() << " Expecting 0" << endl;
    cout << m1.isPassMove() << " Expecting 1" << endl;
    cout << m1.isPickupMove() << " Expecting 0" << endl;
    cout << m1.isSaveMove() << " Expecting 0" << endl;
    cout << m1.isQuitMove() << " Expecting 0" << endl;
    //save move
    Move m2("S");
    cout << m2.getElevatorId() << " Expecting -1" << endl;
    cout << m2.getTargetFloor() << " Expecting -1" << endl;
    cout << m2.getNumPeopleToPickup() << " Expecting 0" << endl;
    cout << m2.getTotalSatisfaction() << " Expecting 0" << endl;
    cout << m2.isPassMove() << " Expecting 0" << endl;
    cout << m2.isPickupMove() << " Expecting 0" << endl;
    cout << m2.isSaveMove() << " Expecting 1" << endl;
    cout << m2.isQuitMove() << " Expecting 0" << endl;
    //quit move
    Move m3("q");
    cout << m3.getElevatorId() << " Expecting -1" << endl;
    cout << m3.getTargetFloor() << " Expecting -1" << endl;
    cout << m3.getNumPeopleToPickup() << " Expecting 0" << endl;
    cout << m3.getTotalSatisfaction() << " Expecting 0" << endl;
    cout << m3.isPassMove() << " Expecting 0" << endl;
    cout << m3.isPickupMove() << " Expecting 0" << endl;
    cout << m3.isSaveMove() << " Expecting 0" << endl;
    cout << m3.isQuitMove() << " Expecting 1" << endl;
    //pickup move
    Move m4("e3p");
    cout << m4.getElevatorId() << " Expecting 3" << endl;
    cout << m4.getTargetFloor() << " Expecting -1" << endl;
    cout << m4.getNumPeopleToPickup() << " Expecting 0" << endl;
    cout << m4.getTotalSatisfaction() << " Expecting 0" << endl;
    cout << m4.isPassMove() << " Expecting 0" << endl;
    cout << m4.isPickupMove() << " Expecting 1" << endl;
    cout << m4.isSaveMove() << " Expecting 0" << endl;
    cout << m4.isQuitMove() << " Expecting 0" << endl;
    //service move
    Move m5("E1F8");
    cout << m5.getElevatorId() << " Expecting 1" << endl;
    cout << m5.getTargetFloor() << " Expecting 8" << endl;
    cout << m5.getNumPeopleToPickup() << " Expecting 0" << endl;
    cout << m5.getTotalSatisfaction() << " Expecting 0" << endl;
    cout << m5.isPassMove() << " Expecting 0" << endl;
    cout << m5.isPickupMove() << " Expecting 0" << endl;
    cout << m5.isSaveMove() << " Expecting 0" << endl;
    cout << m5.isQuitMove() << " Expecting 0" << endl;
    
    Move m6("E1F0");
    cout << m6.getElevatorId() << " Expecting 1" << endl;
    cout << m6.getTargetFloor() << " Expecting 0" << endl;
    cout << m6.getNumPeopleToPickup() << " Expecting 0" << endl;
    cout << m6.getTotalSatisfaction() << " Expecting 0" << endl;
    cout << m6.isPassMove() << " Expecting 0" << endl;
    cout << m6.isPickupMove() << " Expecting 0" << endl;
    cout << m6.isSaveMove() << " Expecting 0" << endl;
    cout << m6.isQuitMove() << " Expecting 0" << endl;
    
    //isValidMove
    Elevator elevators[NUM_ELEVATORS];
    cout << m1.isValidMove(elevators) << " Expecting 1" << endl;
    cout << m2.isValidMove(elevators) << " Expecting 1" << endl;
    cout << m3.isValidMove(elevators) << " Expecting 1" << endl;
    cout << m4.isValidMove(elevators) << " Expecting 0" << endl;
    cout << m5.isValidMove(elevators) << " Expecting 1" << endl;
    
    Move m7("e3f3");
    cout << m7.isValidMove(elevators) << " Expecting 0" << endl;
    Move m8("e2f9");
    cout << m8.isValidMove(elevators) << " Expecting 1" << endl;
    Move m9("e0p");
    cout << m9.isValidMove(elevators) << " Expecting 1" << endl;
    
}

void test_building() {
    cout << "testing building():" << endl;
    
    //update
    Building b;
    Person p1("7f5t8a1");
    Person p2("7f5t9a2");
    Person p3("7f5t1a3");
    b.getFloorByFloorNum(5).addPerson(p1, 3);
    b.getFloorByFloorNum(5).addPerson(p2, 4);
    b.getFloorByFloorNum(5).addPerson(p3, -4);
    b.prettyPrintBuilding(cout);
    
    Move m1("e1f5");
    b.tick(m1);
    b.prettyPrintBuilding(cout);
    
    //pass move
    Move m2("");
    b.tick(m2);
    b.prettyPrintBuilding(cout);

    Move m3("");
    b.tick(m3);
    b.prettyPrintBuilding(cout);
    
    Move m4("");
    b.tick(m4);
    b.prettyPrintBuilding(cout);
    
    Move m5("");
    b.tick(m5);
    b.prettyPrintBuilding(cout);
    
    
    //pickup move

    Move m6("e1p");
    b.tick(m6);
    b.prettyPrintBuilding(cout);
    
}
