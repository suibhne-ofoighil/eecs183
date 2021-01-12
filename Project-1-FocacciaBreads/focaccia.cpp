/**
 * focaccia.cpp
 * EECS 183: Project 1, Fall 2020
 * Suibhne O'Foighil
 * suibhne@umich.edu
 * makes a shopping list for a focaccia baking operation
 */


#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){

// declare pluralization function

    string pluralize(string singular, string plural, int number);

// our conversion metrics for later calculations

    const double PEOPLE_PER_LOAF = 4.0;
    const double FLOUR_CUPS_PER_LOAF = 5;
    const double YEAST_TEASPOONS_PER_LOAF = (7/4.0); 
    const double SALT_TEASPOONS_PER_LOAF = (15/8.0); 
    const double OLIVE_OIL_TABLESPOONS_PER_LOAF = 2; 

    const double FLOUR_CUPS_PER_BAG = 20;
    const double YEAST_TEASPOONS_PER_PACKAGE = 2.25;
    const double SALT_TEASPOONS_PER_CANISTER = (30/5.0);
    const double OLIVE_OIL_TABLESPOONS_PER_BOTTLE = (500/14.8);

    const double FLOUR_BAG_COST = 2.69;
    const double YEAST_PACKAGE_COST = 0.40;
    const double SALT_CANISTER_COST = 0.49;
    const double OLIVE_OIL_BOTTLE_COST = 6.39;

// user input:

    int people = 0;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl;

    int loaves = ceil(people / PEOPLE_PER_LOAF);

// Here are the calculations for ingrediants

    int flourBags = ceil(loaves * FLOUR_CUPS_PER_LOAF / FLOUR_CUPS_PER_BAG);
    int yeastPackages = ceil(loaves * YEAST_TEASPOONS_PER_LOAF / YEAST_TEASPOONS_PER_PACKAGE);
    int saltCanisters = ceil(loaves * SALT_TEASPOONS_PER_LOAF / SALT_TEASPOONS_PER_CANISTER);
    int oliveOilBottles = ceil(loaves * OLIVE_OIL_TABLESPOONS_PER_LOAF / OLIVE_OIL_TABLESPOONS_PER_BOTTLE);

//  Here are the calculations for costs:

    double flourCosts = flourBags * FLOUR_BAG_COST;
    double yeastCosts = yeastPackages * YEAST_PACKAGE_COST;
    double saltCosts = saltCanisters * SALT_CANISTER_COST;
    double oliveOilCosts = oliveOilBottles * OLIVE_OIL_BOTTLE_COST;

    double totalCosts = flourCosts + yeastCosts + saltCosts + oliveOilCosts;

// Here is the output -- The Shopping List...

    cout << endl;


    cout << "You need to make: " << loaves << " " << pluralize("loaf", "loaves", loaves);
    cout << " of focaccia" << endl;


    cout << endl;


    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;


    cout << flourBags << " " << pluralize("bag", "bags", flourBags);
    cout << " of flour" << endl;
    
    cout << yeastPackages << " " << pluralize("package", "packages", yeastPackages);
    cout << " of yeast" << endl;

    cout << saltCanisters << " " << pluralize("canister", "canisters", saltCanisters); 
    cout << " of salt" << endl;

    cout << oliveOilBottles << " " << pluralize("bottle", "bottles", oliveOilBottles);
    cout << " of olive oil" << endl;


    cout << endl;


    cout << "Total expected cost of ingredients: $" << totalCosts << endl;


    cout << endl;


    cout << "Have a great socially-distanced party!" << endl;
    return 0;
}

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
