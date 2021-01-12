/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Suibhne O'Foighil
 * Uniquename: suibhne
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Graphics();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Circle();
    test_Color();
    test_Graphics();
    test_Line();
    test_Point();
    test_Rectangle();
    test_Triangle();
    
    
    // call other test functions here
    
    return;
}

void test_Point() {
        // test of default constructor
    cout << "Testing Point():"  << endl;
    
    Point p1;
    p1.setX(5);
    p1.setY(3);
    cout << "Expecting: ( 5, 3 ), Actual: "
         << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    Point p2(3, 9);
    cout << "Expecting: ( 3, 9 ), Actual: "
         << "( " << p2.getX()
         << ", " << p2.getY()
         << " )" << endl;
    
    Point p3(-29, 102);
    cout << "Expecting: ( 0, 100 ), Actual: ";
    p3.write(cout);
    cout << endl;
    
    Point p4;
    p4.setX(-100);
    p4.setY(-100);
    cout << "Expecting: ( 0, 0 ), Actual: "
         << p4 << endl;
    
    Point p5;
    p5.read(cin);
    p5.write(cout);
    cout << endl;
    
    Point p6;
    cin >> p6;
    cout << p6 << endl;
    
    Point p7;
    cout << "Expecting: ( 0, 0 ), Actual: ";
    p7.write(cout);
    cout << endl;
    
    return;
}

void test_Color() {
    cout << "Testing Color(): " << endl;
    
    Color c1;
    cout << "Expecting: 0 0 0, Actual: " <<
    c1.getRed() << " " << c1.getGreen() << " " << c1.getBlue() << endl;
    
    Color c2(255, 0, 0);
    cout << "Expecting: 255 0 0, Actual: " <<
    c2.getRed() << " " << c2.getGreen() << " " << c2.getBlue() << endl;
    
    Color c3(45, 992, 250);
    cout << "Expecting: 45 255 250, Actual: " <<
    c3.getRed() << " " << c3.getGreen() << " " << c3.getBlue() << endl;
    
    Color c4;
    c4.setRed(-200);
    c4.setGreen(-200);
    c4.setBlue(-200);
    cout << "Expecting: 0 0 0, Actual: " <<
    c4.getRed() << " " << c4.getGreen() << " " << c4.getBlue() << endl;
    
    Color c5;
    c5.setRed(1200);
    c5.setGreen(1200);
    c5.setBlue(1200);
    cout << "Expecting: 255 255 255, Actual: " <<
    c5.getRed() << " " << c5.getGreen() << " " << c5.getBlue() << endl;
    
    c5.setRed(172);
    c5.setGreen(89);
    c5.setBlue(0);
    cout << "Expecting: 172 89 0, Actual: " <<
    c5.getRed() << " " << c5.getGreen() << " " << c5.getBlue() << endl;
    
    c5.setRed(-12);
    c5.setGreen(251);
    c5.setBlue(255);
    cout << "Expecting: 0 251 255, Actual: " <<
    c5.getRed() << " " << c5.getGreen() << " " << c5.getBlue() << endl;
    
    c5.setRed(89);
    c5.setGreen(-124);
    c5.setBlue(256);
    cout << "Expecting: 89 0 255, Actual: " <<
    c5.getRed() << " " << c5.getGreen() << " " << c5.getBlue() << endl;
    
    c5.setRed(10);
    c5.setGreen(12);
    c5.setBlue(133);
    cout << "Expecting: 10 12 133, Actual: " <<
    c5.getRed() << " " << c5.getGreen() << " " << c5.getBlue() << endl;
    
    c5.setRed(1209);
    c5.setGreen(89);
    c5.setBlue(-1);
    cout << "Expecting: 255 89 0, Actual: " <<
    c5.getRed() << " " << c5.getGreen() << " " << c5.getBlue() << endl;
    
    Color c6;
    cin >> c6;
    cout << c6 << endl;
    
    Color c7;
    c7.read(cin);
    c7.write(cout);
    cout << endl;
    
    Color c8;
}

void test_Graphics() {
    cout << "Testing Graphics(): " << endl;
    
    //testing Default constructor()
    Graphics g;
    g.writeFile("test_output.bmp");
    
    //testing setPixel
    Graphics g2;
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(i, 49, Color(255, 0, 0));
    }
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(49, i, Color(255, 0, 0));
    }
    
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(i, 200, Color(0, 2343, 0));
    }
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(200, i, Color(0, 2323, 0));
    }
    
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(i, -123, Color(-123, -123, 200));
    }
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(-123, i, Color(-123, -123, 900));
    }
    
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(i, i, Color(0, 255, 0));
    }
    
    for (int i = 0; i < DIMENSION; ++i) {
        g2.setPixel(DIMENSION - i - 1, i, Color(0, 0, 255));
    }
    
    g2.writeFile("test_output2.bmp");
    
    //testing clear()
    g2.clear();
    g2.writeFile("test_output3.bmp");
}

void test_Line() {
    cout << "Testing Line():" << endl;
    
    //Default constructor - idk how to test.
    Line line;
    
    line.write(cout);
    cout << endl;
    
    Point start;
    Point end;
    Color cl;
    
    Line ln(start, end, cl);
    
    ln.write(cout);
    cout << endl << ln << endl;
    
    //Overloaded constrcutor
    Point startPt(2, 2);
    Point endPt(50, 60);
    Color color(255, 0, 0);
    
    Line line1(startPt, endPt, color);
    
    line1.write(cout);
    cout << endl;
    
    Point startPt2(-100, 1000);
    Point endPt2(-22, 90);
    Color color2(933, -122, 255);
    
    Line line2(startPt2, endPt2, color2);
    
    cout << "Overloaded: " << line1 << endl;
    cout << "Overloaded: " << line2 << endl;
    
    line2.write(cout);
    cout << endl;
    
    //setStart() and setEnd()
    cout << "Before: " << line << endl;
    line.write(cout);
    cout << endl;
    Point startPt3(2, 5);
    Point endPt3(50, 63);
    line.setStart(startPt3);
    line.setEnd(endPt3);
    cout << "After:" << line << endl;
    cout << "Before: " << line2 << endl;
    line.write(cout);
    cout << endl;
    Point startPt4(100, 1000);
    Point endPt4(-111, -5);
    line2.setStart(startPt4);
    line2.setEnd(endPt4);
    cout << "After: " << line2 << endl;
    line2.write(cout);
    cout << endl;
    
    //getStart() and getEnd()
    cout << "Start: " << line.getStart() << endl <<
            "End: " << line.getEnd() << endl;
    cout << "Start: " << line1.getStart() << endl <<
            "End: " << line1.getEnd() << endl;
    cout << "Start: " << line2.getStart() << endl <<
            "End: " << line2.getEnd() << endl;
    
    //setColor() and getColor()
    Color color3(0, 255, 0);
    cout << "Constructor Color: " << line.getColor() << endl;
    line.setColor(color3);
    cout << "Setter Color: " << line.getColor() << endl;
    
    line.write(cout);
    cout << endl << line << endl;
    
    //read stream
    Line line3;
    cin >> line3;
    
    //write stream;
    cout << line3 << endl;
    line3.write(cout);
    cout << endl;
    
}

void test_Triangle() {
    cout << "Testing Triangle():" << endl;
    
    //default constructor
    Triangle t0;
    
    cout << t0 << endl;
    
    cout << "Set Vertex One = " << t0.getVertexOne() <<
            "  "               << t0.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t0.getVertexTwo() <<
            "  "               << t0.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t0.getVertexThree() <<
            "  "            << t0.getVertexThreeColor() << endl;
    
    //overloaded constructor
    Point t1pt1(23, 50);
    Point t1pt2(42, 62);
    Point t1pt3(42, 38);
    Color t1color1 (255, 0, 255);
    Triangle t1(t1pt1, t1pt2, t1pt3, t1color1);
    
    cout << t1 << endl;
    
    cout << "Set Vertex One = " << t1.getVertexOne() <<
            "  "               << t1.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t1.getVertexTwo() <<
            "  "               << t1.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t1.getVertexThree() <<
            "  "            << t1.getVertexThreeColor() << endl;
    
    //overloaded constructor 2
    Point t2pt1(45, 40);
    Point t2pt2(77, 23);
    Point t2pt3(77, 77);
    Color t2color1(170, 0, 170);
    Color t2color2(-123123, -123, 2304);
    Color t2color3(155, 893, -823);
    Color t2color4(809, 72, 133);
    Triangle t2(t2pt1, t2color1,
                t2pt2, t2color2,
                t2pt3, t2color3);
    
    cout << t2 << endl;
    
    cout << "Set Vertex One = " << t2.getVertexOne() <<
            "  "               << t2.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t2.getVertexTwo() <<
            "  "               << t2.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t2.getVertexThree() <<
            "  "            << t2.getVertexThreeColor() << endl;
    
    t2.setColor(t2color1);
    
    cout << "Set Vertex One = " << t2.getVertexOne() <<
            "  "               << t2.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t2.getVertexTwo() <<
            "  "               << t2.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t2.getVertexThree() <<
            "  "            << t2.getVertexThreeColor() << endl;
    
    t2.setVertexOneColor(t2color2);
    
    cout << "Set Vertex One = " << t2.getVertexOne() <<
            "  "               << t2.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t2.getVertexTwo() <<
            "  "               << t2.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t2.getVertexThree() <<
            "  "            << t2.getVertexThreeColor() << endl;
    
    t2.setVertexTwoColor(t2color3);
    
    cout << "Set Vertex One = " << t2.getVertexOne() <<
            "  "               << t2.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t2.getVertexTwo() <<
            "  "               << t2.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t2.getVertexThree() <<
            "  "            << t2.getVertexThreeColor() << endl;
    
    t2.setVertexThreeColor(t2color3);
    
    cout << "Set Vertex One = " << t2.getVertexOne() <<
            "  "               << t2.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t2.getVertexTwo() <<
            "  "               << t2.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t2.getVertexThree() <<
            "  "            << t2.getVertexThreeColor() << endl;
    
    //3 Color setter
    Color t1color2(100, 0, 100);
    t1.setColor(t1color2);
    
    cout << t1 << endl;
    
    cout << "Set Vertex One = " << t1.getVertexOne() <<
            "  "               << t1.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t1.getVertexTwo() <<
            "  "               << t1.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t1.getVertexThree() <<
            "  "            << t1.getVertexThreeColor() << endl;
    
    //Vertex Setters ... Getters
    Point t0pt1(20, 50);
    Point t0pt2(80, 20);
    Point t0pt3(80, 80);
    Color t0color1(255, 0, 0);
    Color t0color2(255, 0, 0);
    Color t0color3(255, 0, 0);
    
    t0.setVertexOne(t0pt1);
    t0.setVertexTwo(t0pt2);
    t0.setVertexThree(t0pt3);
    t0.setVertexOneColor(t0color1);
    t0.setVertexTwoColor(t0color2);
    t0.setVertexThreeColor(t0color3);
    
    cout << "Set Vertex One = " << t0.getVertexOne() <<
            "  "               << t0.getVertexOneColor() << endl;
    cout << "Set Vertex Two = " << t0.getVertexTwo() <<
            "  "               << t0.getVertexTwoColor() << endl;
    cout << "Set Vertex Three = " << t0.getVertexThree() <<
            "  "            << t0.getVertexThreeColor() << endl;
    
    //reading in + writing out triangles
    Triangle t3;
    cout << "Read in Triangle in forms: " << endl <<
            "\"point1 color1 point2 color2 point3 color3\" or" << endl <<
            "\"point1 point2 point3 color\"" << endl;
    cin >> t3;
    cout << t3 << endl;
}

void test_Circle() {
    cout << "Testing Circle():" << endl;
    
    //constructor
    Circle circle;
    
    cout << circle << endl;
    
    //overloaded constructor
    Point pt2(50, 50);
    int r2 = 3;
    Color c2(0, 20, 100);
    Circle circle2(pt2, r2, c2);
    
    cout << circle2 << endl;
    
    Point pt3(100, 100);
    int r3 = 0;
    Color c3(-12, 20, 360);
    Circle circle3(pt3, r3, c3);
    
    cout << circle3 << endl;
    
    Point pt5(-100, 123098);
    int r5 = 500;
    Color c5(-123, -983, -8237);
    Circle circle5(pt5, r5, c5);
    
    cout << circle5 << endl;
    
    Point pt6(78, 80);
    int r6 = 15;
    Color c6(80, 80, 80);
    Circle circle6(pt6, r6, c6);
    
    cout << circle6 << endl;
    
    //setters
    Point pt(50, 60);
    int r = -99;
    Color c(20, 0, 100);
    circle.setCenter(pt);
    circle.setRadius(r);
    circle.setColor(c);
    
    //getters
    cout << circle.getCenter() << "  " <<
            circle.getRadius() << "  " <<
            circle.getColor()  << endl;
    
    cout << circle2.getCenter() << "  " <<
            circle2.getRadius() << "  " <<
            circle2.getColor()  << endl;
    
    //read and write
    cout << circle3 << endl;
    Circle circle4;
    cin >> circle4;
    cout << circle4 << endl;
}

void test_Rectangle() {
    cout << "Testing Rectangle(): " << endl;
    
    //default constructor
    Rectangle rect;
    
    //overloaded constructor 1
    Point rect2pt1(12,12);
    Point rect2pt2(78,78);
    Color rect2color(0, 90, 20);
    Rectangle rect2(rect2pt1, rect2pt2, rect2color);
    cout << rect2 << endl;
    
    //overloaded constructor 2
    Point rect3pt1(15,15);
    Point rect3pt2(75,75);
    Color rect3TopLeft(20, 20, 20);
    Color rect3TopRight(50, 50, 50);
    Color rect3BottomLeft(50, 50, 50);
    Color rect3BottomRight(100, 100, 100);
    Rectangle rect3(rect3pt1, rect3pt2,
                    rect3TopLeft,
                    rect3TopRight,
                    rect3BottomRight,
                    rect3BottomLeft);
    cout << rect3 << endl;
    
    //getters and setters
    cout << rect << endl;
    Point rect4pt1(20,20);
    Point rect4pt2(60,60);
    Color rect4TopLeft(100, 100, 100);
    Color rect4TopRight(50, 50, 50);
    Color rect4BottomLeft(50, 50, 50);
    Color rect4BottomRight(20, 20, 20);
    Color rect4Color;
    rect.setStart(rect4pt1);
    rect.setEnd(rect4pt2);
    rect.setColorTopLeft(rect4TopLeft);
    rect.setColorTopRight(rect4TopRight);
    rect.setColorBottomLeft(rect4BottomLeft);
    rect.setColorBottomRight(rect4BottomRight);
    
    //mismatch between overall setter and individ setters
    cout << rect << endl;
    rect.setColor(rect4Color);
    cout << rect << endl;
    rect.setColorTopLeft(rect3TopLeft);
    cout << rect << endl;
    rect.setColor(rect4TopLeft);
    cout << rect << endl;
    rect.setColorTopRight(rect3TopRight);
    cout << rect << endl;
    rect.setColor(rect4TopRight);
    cout << rect << endl;
    rect.setColorBottomLeft(rect3BottomLeft);
    cout << rect << endl;
    rect.setColor(rect4BottomLeft);
    cout << rect << endl;
    rect.setColorBottomRight(rect3BottomRight);
    cout << rect << endl;
    rect.setColor(rect4BottomRight);
    cout << rect << endl;
    rect.setColorTopLeft(rect3TopLeft);
    cout << rect << endl;
    
    cout << rect.getStart() << " " << rect.getEnd() << "  " <<
            rect.getColorTopLeft() << "  " <<
            rect.getColorTopRight() << "  " <<
            rect.getColorBottomRight() << "  " <<
            rect.getColorBottomLeft() << endl;
            
    Rectangle rect5;
    cin >> rect5;
    cout << rect5 << endl;
    
}
