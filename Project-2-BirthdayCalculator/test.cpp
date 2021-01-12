/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * <#Name#>
 * <#Uniqname#>
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,
    // test_getMenuChoice();
    test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();

    
    // Add more calls as you implement more functions.
    // While you're working on a function, it can be useful to comment
    //  out the calls to other functions' tests.

    // Make sure the only function you test in a test function
    //  like test_isGregorianDate is that function (isGregorianDate),
    //  or it may cause issues with the autograder.
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    cout << "Please enter -1 then 1:";
    int choice4 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice4 << endl;

    // Write additional tests here
}

void test_isGregorianDate()
{
    // isGregorianDate does not read from cin, so
    // all its tests can be run automatically
    cout << "Now testing function isGregorianDate()\n";
    cout << "9/2/2019:  Expected: 1, Actual: " << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: " << isGregorianDate(1, 31, 1001) << endl;
    cout << "9/13/1752: Expected: 0, Actual: " << isGregorianDate(9, 13, 1752) << endl;
    cout << "9/15/1752: Expected: 1, Actual: " << isGregorianDate(9, 15, 1752) << endl;
    cout << "12/13/1752: Expected: 1, Actual: " << isGregorianDate(12, 13, 1752) << endl;
    cout << "6/30/1982: Expected: 1, Actual: " << isGregorianDate(6, 30, 1982) << endl;
    cout << "3/18/1423: Expected: 0, Actual: " << isGregorianDate(3, 18, 1423) << endl;
    cout << "-12/-2/-122: Expected: 0, Actual: " << isGregorianDate(-12, -2, -122) << endl;

    // Write your tests here
}

void test_isLeapYear()
{
    cout << "Testing isLeapYear()" << endl;
    cout << "1768: Expected: 1, Actual: " << isLeapYear(1768) << endl;
    cout << "1800: Expected: 0, Actual: " << isLeapYear(1800) << endl;
    cout << "2000: Expected: 1, Actual: " << isLeapYear(2000) << endl;
    cout << "1111: Expected: 0, Actual: " << isLeapYear(1111) << endl; 
    cout << "500: Expected: 0, Actual: " << isLeapYear(500) << endl;
    cout << "1600: Expected: 1, Actual: " << isLeapYear(1600) << endl;
    cout << "-1222: Expected: 0, Actual: " << isLeapYear(-1222) << endl;
    cout << "1200: Expected: 1, Actual: " << isLeapYear(644) << endl;
//     1768	true
// 1800	false
// 2000	true
}

void test_isValidDate()
{
    cout << "Testing isValidDate()" << endl;
    cout << "13/20/1980: Expected: 0, Actual: " << isValidDate(13, 20, 1980) << endl;
    cout << "1/32/1980: Expected: 0, Actual: " << isValidDate(1, 32, 1980) << endl;
    cout << "4/31/2015: Expected: 0, Actual: " << isValidDate(4, 31, 2015) << endl;
    cout << "5/23/1300: Expected: 0, Actual: " << isValidDate(5, 23, 1300) << endl;
    cout << "2/29/2001: Expected: 0, Actual: " << isValidDate(2, 29, 2001) << endl;
    cout << "2/29/2000: Expected: 1, Actual: " << isValidDate(2, 29, 2000) << endl;
    cout << "-1/9/-1: Expected: 0, Actual: " << isValidDate(-1, 9, -1) << endl;
    cout << "11/30/1752: Expected: 0, Actual: " << isValidDate(11, 30, 1752) << endl;
    cout << "2/9/1752: Expected: 0, Actual: " << isValidDate(2, 9, 1752) << endl;
    cout << "11/31/1867: Expected: 0, Actual: " << isValidDate(11, 31, 1867) << endl;
}

void test_determineDay()
{
    cout << "Now testing determineDay()" << endl;
    cout << "1/29/2064: Expected: 3, Actual: " << determineDay(1, 29, 2064) << endl;
    cout << "9/29/2020: Expected: 3, Actual: " << determineDay(9, 29, 2020) << endl;
    cout << "2/17/2018: Expected: 0, Actual: " << determineDay(2, 17, 2018) << endl;
    cout << "5/19/2016: Expected: 5, Actual: " << determineDay(5, 19, 2016) << endl;
    cout << "2/27/2000: Expected: 1, Actual: " << determineDay(2, 27, 2000) << endl;
    cout << "2/27/1600: Expected: 1, Actual: " << determineDay(2, 27, 1600) << endl;
    cout << "2/27/1800: Expected: 5, Actual: " << determineDay(2, 27, 1800) << endl;
    cout << "12/19/1950: Expected: 3, Actual: " << determineDay(12, 19, 1950) << endl;
    cout << "10/1/1792: Expected: 2, Actual: " << determineDay(10, 1, 1792) << endl;
    cout << "9/13/1982: Expected: 2, Actual: " << determineDay(9, 13, 1982) << endl;

}

void test_printDayOfBirth()
{
    // printDayOfBirth prints to cout rather than
    // returning a value.
    cout << "Now testing printDayOfBirth()" << endl;
    cout << "0: Expected: Saturday, Actual: "; 
    printDayOfBirth(0);
    cout << endl;
    cout << "1: Expected: Sunday, Actual: "; 
    printDayOfBirth(1);
    cout << endl;
    cout << "2: Expected: Monday, Actual: ";
    printDayOfBirth(2);
    cout << endl;
    cout << "3: Expected: Tuesday, Actual: ";
    printDayOfBirth(3);
    cout << endl;
    cout << "4: Expected: Wednesday, Actual: ";
    printDayOfBirth(4);
    cout << endl;
    cout << "5: Expected: Thursday, Actual: ";
    printDayOfBirth(5);
    cout << endl;
    cout << "6: Expected: Friday, Actual: ";
    printDayOfBirth(6);
    cout << endl;
    cout << "7: Expected: Invalid pass through value, Actual: ";
    printDayOfBirth(7);
    cout << endl;

    // Write your tests here
}

void test_determineDayOfBirth()
{
    cout << "Now testing determineDayOfBirth()" << endl;
    cout << "Enter 9/13/1982, Expected: Monday" << endl;
    determineDayOfBirth();
}

void test_print10LeapYears()
{
    cout << "Now testing print10LeapYears()" << endl;
    print10LeapYears();
}