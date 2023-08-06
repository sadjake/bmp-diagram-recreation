// Each Triangle has the a length (x extent)
// a width (y extent), a location used for graphic
// display (xlocation, ylocation), and a color
// for grapic display.All distances and
// locations are integers (number of pixels)
// The upper right hand corner is (0,0)
// y coordinate increased downward
// Author: Janice Regan 2017
#ifndef TriangleFlag
#define TriangleFlag
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "Colour.h"
using namespace std;
class Triangle
{
public:
//default constructor: no arguments, no return type
//define if class has any other constructors, or if class
//includes deep memory (pointers) or static counters
Triangle();
//other intializing constructors
Triangle( int xLocationValue, int yLocationValue,
int sideLengthValue, Colour blockColourValue);
Triangle( int xLocationValue, int yLocationValue,
Colour blockColourValue);
//copy constructor: needed for function calls
Triangle(const Triangle& toBeCopied);
//destructor: define when class has deep memory or static counters
~Triangle();
//accessor functions
int GetSideLength() const;
int GetXLocation() const;
int GetYLocation() const;
Colour GetTriangColour() const;
//accessor functions for static members are static functions
//this allows the static members to be accessed before any
//object of the class are created
static int GetTrianglesCreated();
static int GetTrianglesExisting();
//mutator functions, in an actual application you would
//write mutator functions only for member variable that
//NEED to be accessed from outside the class, This would
//be the smallest subSet of member variables possible
//(to preserve encapsulation)
void SetTriangColour(const Colour blockColorValue);
void SetSideLength(const int setSideLengthValue);
void SetXLocation(const int xLocationValue);
void SetYLocation(const int yLocationValue);
//mutator functions for static members are static functions
//this allows the static members to be changed before any
//object of the class are created
static void SetTrianglesCreated(int numberCreated);
static void SetTrianglesExisting(int numberExisting);
//friend function
//A friend function is not a member function but is
//allowed to directly access the private members of the class
friend ostream& operator << (ostream& os,
const Triangle& myTriangle);
//member function to plot a Triangle to a bitmap
//myImageValue is a bitmap
void TriangleDisplay(BMP& myImageValue, string theOutputFile);
void TrianglePrint();
void TriangleDivide(Triangle* subTriangleList );
//add overloaded operator for last part of problem 1
const Triangle& operator = (const Triangle& Triangle2);
bool operator==(const Triangle& Triangle2) const;
bool operator > (const Triangle& Triangle2) const;
private:
// static members counting the number of objects in this
// class have been created by the application, and how
// many objects of this class presently exist
static int TrianglesCreated;
static int TrianglesExisting;
// Members expressing properties of a Triangle
int sideLength;
int xLocation;
int yLocation;
Colour triangColour;
};
//extern ostream& operator << (ostream& os, const Triangle& myTriangle);
#endif