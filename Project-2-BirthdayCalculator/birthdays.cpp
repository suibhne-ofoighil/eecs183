/**
 * birthdays.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * <Suibhne O'Foighil>
 * <suibhne>
 *
 * EECS 183: Project 2
 *
 * <This program is the Birthday Calculator:
    computes the day of your birth and prints
    the next 10 leap years after any given date>
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();

//main birthday function

void birthdays() {  
    printHeading();
    //deactivating the calculator variable
    int gameover = false;
    while (!(gameover)) 
    {
        int choice = getMenuChoice();
        if (choice == 1) {
            determineDayOfBirth();
        } else if (choice == 2) {
            print10LeapYears();
        } else if (choice == 3) {
            gameover = true;
        }
    }
    printCloser();
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    cout << endl;
    printMenu();
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3) {
        cout << endl;
        cout << "Invalid menu choice" << endl;
        // correct cin failstate if necessary      
        if (cin.fail()) {
            cin.clear();
        }    
        // clear cin buffer for new input
        string junk;
        getline(cin, junk);
        // reprint menu & get another input
        cout << endl;
        printMenu();
        cin >> choice;
    }
    return choice;
}

bool isGregorianDate(int month, int day, int year) {
    if (year > 1752) {
        return true;
    } else if (month > 9 && year == 1752) {
        return true;
    } else if (month >= 9 && day >=14 && year == 1752) {
        return true;
    } else {
        return false;
    }
}

bool isLeapYear(int year) {
    // Leap year is only on the turn of the century, every 4th century.
    // eg. the year: 2000
    if (year % 100 == 0 && year % 400 != 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}


bool isValidDate(int month, int day, int year) {
    // The date is only valid if it is a Gregorian date.
    if (isGregorianDate(month, day, year) && day > 0 && month > 0) {
        // accounting for the months with 31 days...
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day <= 31) {
                return true;
            }
        // accounting for the months with 30 days
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day <= 30) {
                return true;
            }
        // accounting for february
        } else if (month == 2) {
            if (day <= 28) {
                return true;
            // and the added day in the case of a leap year. 
            } else if (isLeapYear(year) && day == 29) {
                return true;
            }
        } 
    } return false;
}


int determineDay(int month, int day, int year) {
    // these are the variables EXPRESSLY USED in Zeller's rule.
    // Be upset with Zeller if these aren't descriptive. 
    int M;
    int D;
    int C;
    int Y;

    // Calendar Adjustments for Zeller's rule application

    if (month == 1 || month == 2) {
        month = month + 12;
        --year;
    }

    // Calculate C (Century) and Y (remainder of Century) Values
    int forthDigitOfYear = year % 10;
    int thirdDigitOfYear = year % 100 - forthDigitOfYear;
    Y = thirdDigitOfYear + forthDigitOfYear;
    C = (year - Y) / 100;
    // assign values to Zeller's rule variables
    M = month;
    D = day;

    // Apply Zeller's rule:
    int dayOfWeek = static_cast<int>(D + floor((13 * (M + 1)) / 5) + Y + floor(Y / 4) + floor(C / 4) + 5 * C) % 7; 
    
    // return the numeric encoding of the day of the week
    return dayOfWeek;
}


void printDayOfBirth(int day) {
    // turns numeric code to string name
    if (day == 0) {
        cout << "Saturday" << endl;
    }
    else if (day == 1) {
        cout << "Sunday" << endl;
    }
    else if (day == 2) {
        cout << "Monday" << endl;
    }
    else if (day == 3) {
        cout << "Tuesday" << endl;
    }
    else if (day == 4) {
        cout << "Wednesday" << endl;
    }
    else if (day == 5) {
        cout << "Thursday" << endl;
    }
    else if (day == 6) {
        cout << "Friday" << endl;
    } 
    else {
        cout << "Invalid pass through value";
    }
    return;
}


void determineDayOfBirth() {
    int month, day, year;
    string junk;
    
    cout << endl;
    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  --> ";
    // parse through cin buffer, according to format above ^^
    cin >> month;
    cin >> junk;
    cin >> day;
    cin >> junk;
    cin >> year;
    // if the date is valid, proceed with calculation
    if (isValidDate(month, day, year)) {

        cout << endl;
        cout << "You were born on a: ";
        printDayOfBirth(determineDay(month, day, year));
        cout << endl;
        cout << "Have a great birthday!!!" << endl
             << endl;

    } else {
        cout << endl
             << "Invalid date" << endl
             << endl;
    }
    return;
}

void print10LeapYears() {
    int year;
    cout << endl
         << "Enter year --> ";
    cin >> year;
    //Checking if year is a Gregorian year, the first was 1752:
    if (year >= 1752) {
        cout << endl;
        //for loop to print the next 10 leap years
        for (int i = 0; i < 10; ++i) {
            //increment to consider all years AFTER (not including) year
            ++year;
            //while loop to skip every non-leap year.
            while(!(isLeapYear(year))) {
            ++year;
            }
            //if while loop fails, isLeapYear(year) returned true. Therefore, a leap year.
            cout << "Leap year is " << year << endl;
        }   
    } 
    cout << endl;
    return;
}
