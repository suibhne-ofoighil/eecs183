/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Suibhne O'Foighil
 * Uniquename: suibhne
 *
 * Rectangle class definitions to create rectangles in pictures.
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;


Rectangle::Rectangle() {
    start = Point();
    end = Point();
    colorTopLeft = Color();
    colorTopRight = Color();
    colorBottomRight = Color();
    colorBottomLeft = Color();
}

Rectangle::Rectangle(Point start_in, Point end_in, Color color_in) {
    start = start_in;
    end = end_in;
    colorTopLeft = color_in;
    colorTopRight = color_in;
    colorBottomRight = color_in;
    colorBottomLeft = color_in;
}

Rectangle::Rectangle(Point start_in, Point end_in, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {
    start = start_in;
    end = end_in;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

void Rectangle::setStart(Point start_in) {
    start = start_in;
}

Point Rectangle::getStart() {
    return start;
}

void Rectangle::setEnd(Point end_in) {
    end = end_in;
}

Point Rectangle::getEnd() {
    return end;
}

void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

void Rectangle::read(istream& ins) {
    Point pt1;
    Point pt2;
    Color topLeft;
    Color topRight;
    Color bottomRight;
    Color bottomLeft;
    Color color;
    
    //if input stream reads in this sequence, it is the first form.
    //If not, it is the second.
    if (ins >> pt1 >> pt2 >> topLeft >> topRight) {
        ins >> bottomRight >> bottomLeft;
        colorTopLeft = topLeft;
        colorTopRight = topRight;
        colorBottomRight = bottomRight;
        colorBottomLeft = bottomLeft;
    } else {
        ins.clear();
        colorTopLeft = topLeft;
        colorTopRight = topLeft;
        colorBottomRight = topLeft;
        colorBottomLeft = topLeft;
    }
    start = pt1;
    end = pt2;
}

void Rectangle::write(ostream& outs) {
    outs << start << " " << end << "  " <<
            colorTopLeft << "  " << colorTopRight << "  " <<
            colorBottomRight << "  " << colorBottomLeft;
    
}

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
