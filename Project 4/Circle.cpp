/**
 * Circle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Suibhne O'Foighil
 * Uniquename: suibhne
 *
 * Circle class definitions for drawing
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;

Circle::Circle() {
    center = Point();
    radius = 0;
    color = Color();
}


Circle::Circle(Point center_in, int radius_in, Color color_in) {
    center = center_in;
    radius = checkRadius(radius_in);
    color = color_in;
}

void Circle::setCenter(Point center_in) {
    center = center_in;
}

Point Circle::getCenter(){
    return center;
}

void Circle::setRadius(int radius_in) {
    radius = checkRadius(radius_in);
}

int Circle::getRadius() {
    return radius;
}

void Circle::setColor(Color color_in) {
    color = color_in;
}

Color Circle::getColor() {
    return color;
}

void Circle::read(istream& ins) {
    Point pt;
    int r;
    Color cl;
    
    if (ins >> pt >> r >> cl) {
        center = pt;
        radius = checkRadius(r);
        color = cl;
    }
}

void Circle::write(ostream& outs) {
    outs << center << "  " << radius << "  " << color;
}

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
