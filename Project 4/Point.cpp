/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Suibhne O'Foighil
 * Uniquename: suibhne
 *
 * Point class definisions - which is basis for other shape classes
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"


int Point::checkRange(int val) {
    if (val < 0) {
        return 0;
    } else if (val >= DIMENSION) {
        return DIMENSION - 1;
    } else {
        return val;
    }
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

void Point::read(istream& ins) {
    char leftBracket;
    int xVal;
    char comma;
    int yVal;
    char rightBracket;
    
    if (ins >> leftBracket >> xVal >> comma >> yVal >> rightBracket)
    {
        x = checkRange(xVal);
        y = checkRange(yVal);
    }
}

void Point::write(ostream& outs) {
    outs << "(" << x << "," << y << ")";
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
