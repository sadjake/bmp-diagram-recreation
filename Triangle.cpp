#include "Triangle.h"
#include "Colour.h"
//#include <iostream>

//using namespace std;

// Initialize static members
int Triangle::TrianglesExisting = 0;
int Triangle::TrianglesCreated = 0;
const double TRIANGLE_SIDE_TO_HEIGHT = 0.86666666;

void Triangle::TriangleDisplay(BMP& myImageValue, string theOutputFile) {
    // initialize yHeight
    int yHeight = static_cast<int>(sideLength * sqrt(3.0)/2.0);
    
    if ((yLocation < 0 || yLocation > pageLength || yLocation + yHeight > pageLength) ||
    (xLocation < 0 || xLocation >= pageWidth || xLocation + sideLength > pageWidth)) {
        cerr << "Point may be located outside of plotting page" << endl;
        return;    
    }
    
    for (int j = yLocation; j < (yLocation + yHeight); j++) {
        
        double yHeightOffset = static_cast<double>(sideLength)/yHeight/2.0;
        // use ceiling for this
        int upperOffsetLimit = static_cast<int>(ceil((j - yLocation + 1) * yHeightOffset));
        // use floor for this
        int lowerOffsetLimit = static_cast<int>(floor((j - yLocation + 1) * yHeightOffset));

    for (int i = 0; i < sideLength; i++) {
            if (i < upperOffsetLimit || i > sideLength - lowerOffsetLimit) {
                continue;
            }

            // alpha
            myImageValue(i+xLocation,j)->Alpha = triangColour.GetAlphaNumber();
            // red
            myImageValue(i+xLocation,j)->Red = triangColour.GetRedNumber();
            // blue
            myImageValue(i+xLocation,j)->Blue = triangColour.GetBlueNumber();
            // green
            myImageValue(i+xLocation,j)->Green = triangColour.GetGreenNumber();
            }
    }

    // write the generated bitmap image to a file
    myImageValue.WriteToFile(theOutputFile.c_str());
}

void Triangle::TriangleDivide(Triangle* TriList) {
    // declare variables
    int halfSideLength;
    int yHalfHeight;
    halfSideLength = sideLength / 2;
    
    yHalfHeight = static_cast<int>(halfSideLength * TRIANGLE_SIDE_TO_HEIGHT);
    TriList[2] = Triangle(xLocation + halfSideLength / 2, yLocation + yHalfHeight, halfSideLength, triangColour);
    TriList[1] = Triangle(xLocation + halfSideLength, yLocation, halfSideLength, triangColour);
    TriList[0] = Triangle(xLocation, yLocation, halfSideLength, triangColour);
}

Triangle::Triangle()
{
    // initialize the values
    sideLength = 10;
    xLocation = 0;
    yLocation = 0;
    triangColour = Colour(0, 0, 0, 255);

    // Increment counters
    TrianglesCreated++;
    TrianglesExisting++;
}

Triangle::Triangle(int xLocationValue, int yLocationValue, int sideLengthValue, Colour blockColourValue) {
    // set sideLength to sideLengthValue
    sideLength = sideLengthValue;

    // increment
    TrianglesCreated++;
    TrianglesExisting++;

    // set triangColour to blockColourValue
    triangColour = blockColourValue;

    int height = static_cast<int> (sideLength * sqrt(3.0) / 2.0);

    if (xLocationValue >= 0 && xLocationValue < pageWidth && yLocationValue >= 0 && yLocationValue < pageLength) {
        xLocation = xLocationValue;
        yLocation = yLocationValue;
    }
        
    else {
        cout << "x position = " << xLocationValue << " and / or y position = " << yLocationValue << " of Triangle object is off the page" << endl;
        xLocation = 0;
        yLocation = 0;
        cout << "x position and y position have been reset to 0" << endl;
    }

    if (xLocation + sideLength > pageWidth) {
        cout << "Triangle object partially off the page\n";
        cout << "xLocation is " << xLocation << endl;
        cout << " sideLength was " << sideLength;
        sideLength = pageWidth - xLocation;
        cout << " sideLength is " << sideLength << endl;
    }

    if (yLocation + height > pageLength) {
        cout << "Triangle object partially off the page\n";
        cout << "yLocation is " << yLocation << endl;
        cout << " sideLength was " << sideLength;
        sideLength = (pageLength - yLocation) / TRIANGLE_SIDE_TO_HEIGHT;
        cout << " sideLength is " << sideLength << endl;
    }
}

Triangle::Triangle(int xLocationValue, int yLocationValue, Colour blockColourValue)
{
    // initialize sideLength to 10
    sideLength = 10;

    // increment
    TrianglesExisting++;
    TrianglesCreated++;

    // set triangColour to blockColourValue
    triangColour = blockColourValue;
    
    if ((xLocationValue >= 0 && xLocationValue < pageWidth) && (yLocationValue >= 0 && yLocationValue < pageLength)) {
        xLocation = xLocationValue;
        yLocation = yLocationValue;
    }

    else {
        cout << "x location = " << xLocation << "and / or y position = " << yLocation << "of Triangle object is off the page '\n'";
        xLocation = 0;
        yLocation = 0;
        cout << "x position and y position have been reset to 0\n";
    }

    if (xLocation + sideLength > pageWidth) {
        cout << "Triangle object partially off the page \n";
        cout << "xlocation is " << xLocation << '\n';
        cout << "sideLength was " << sideLength;
        sideLength = pageWidth - xLocation;
        cout << " sideLength is " << sideLength << endl;
    }

    if (yLocation + sideLength > pageLength) {
        cout << "Triangle object partially off the page \n";
        cout << "ylocation is " << yLocation << '\n';
        cout << "sideLength was " << sideLength;
        sideLength = (pageLength - yLocation) / (sqrt(3.0) / 2.0);
        cout << " sideLength is " << sideLength << endl;
    }
}

//copy constructor: needed for function calls
Triangle::Triangle(const Triangle& toBeCopied) {
    sideLength = toBeCopied.sideLength;
    xLocation = toBeCopied.xLocation;
    yLocation = toBeCopied.yLocation;
    triangColour = toBeCopied.triangColour;

    // increment counters
    TrianglesCreated++;
    TrianglesExisting++;
}

//destructor 
Triangle::~Triangle()
{
    TrianglesExisting--;
}

int Triangle::GetSideLength() const
{
    return sideLength;
}

int Triangle::GetXLocation() const
{
    return xLocation;
}

int Triangle::GetYLocation() const
{
    return yLocation;
}

Colour Triangle::GetTriangColour() const
{
    return triangColour;
}

int Triangle::GetTrianglesCreated()
{
    return TrianglesCreated;
}

int Triangle::GetTrianglesExisting()
{
    return TrianglesExisting;
}

void Triangle::SetTriangColour(const Colour blockColorValue)
{
    triangColour = blockColorValue;
}

void Triangle::SetSideLength(const int setSideLengthValue)
{
    sideLength = setSideLengthValue;

    if (xLocation + sideLength >= pageWidth) {
        cout << "Triangle object partially off the page \n ";
        cout << "sideLength reset to assure the whole triangle is on the page\n";
        cout << "xlocation is " << xLocation << '\n';
        cout << " sideLength was " << sideLength;
        sideLength = pageWidth - xLocation;
        cout << "sideLength is " << sideLength;
    }

    if  (yLocation + sideLength >= pageLength) {
        cout << "Triangle object partially off the page \n";
        cout << "sideLength reset to assure the whole triangle is on the page\n";
        cout << "ylocation is " << yLocation << '\n';
        cout << "sideLength was " << sideLength;
        sideLength = (pageLength - yLocation) / (sqrt(3.0)/2.0) ;
        cout << " sideLength is " << sideLength << endl;
    }
}

// personal note: left from here - starting fixing code from here again when I wake up
void Triangle::SetXLocation(const int xLocationValue)
{
    // xLocation as xLocationValue
    xLocation = xLocationValue;

    if (xLocation >= pageWidth || xLocation < 0) {
        // set both xLocation and yLocation to 0
        xLocation = 0;
        yLocation = 0;
    }

    if( xLocation + sideLength > pageWidth) {
        sideLength = pageWidth-xLocation;
    }
}

////
void Triangle::SetYLocation(const int yLocationValue)
{
    yLocation = yLocationValue;
    if (yLocation >= pageLength || yLocation < 0) {
        // set both xLocation and yLocation to 0
        xLocation = 0;
        yLocation = 0;
    }

    if( yLocation + sideLength > pageLength) {
        sideLength = (pageLength - yLocation) / (sqrt(3.0)/2.0);
    }
}

void Triangle::SetTrianglesCreated(int numberCreated)
{
    TrianglesCreated = numberCreated;
}

void Triangle::SetTrianglesExisting(int numberExisting)
{
    TrianglesExisting = numberExisting;
}

void Triangle::TrianglePrint()
{
    cout << setw(20) << "SideLength" << setw(9) << sideLength << endl;
    cout << setw(20) << "xLocation" << setw(9) << xLocation << endl;
    cout << setw(20) << "yLocation" << setw(9) << yLocation << endl;
    cout << setw(20) << "TrianglesCreated" << setw(9) << TrianglesCreated << endl;
    cout << setw(20) << "TrianglesExisting" << setw(9) << TrianglesExisting << endl;
    cout << setw(20) << "Trianglecolour" << setw(9) << triangColour << endl;
}

// personal note: fix parts from here again
const Triangle& Triangle::operator = (const Triangle& Triangle2)
{
    sideLength = Triangle2.sideLength;
    xLocation = Triangle2.xLocation;
    yLocation = Triangle2.yLocation;
    triangColour = Triangle2.triangColour;

    // return a reference to the updated current object 'this'
    // allows to continue working with modified tria
    return *this;
}

bool Triangle::operator == (const Triangle& Triangle2) const
{
    if(sideLength == Triangle2.sideLength && xLocation == Triangle2.xLocation &&
        yLocation == Triangle2.yLocation && triangColour == Triangle2.triangColour) {
        return true;
    }   
    else {
        return false;
    }
}

ostream& operator << (ostream& os, const Triangle& myTriangle)
{
    os << setw(20) << "sideLength" << setw(9) << myTriangle.sideLength << endl;
    os << setw(20) << "xLocation " << setw(9) << myTriangle.xLocation << endl;
    os << setw(20) << "yLocation " << setw(9) << myTriangle.yLocation << endl;
    os << setw(20) << "TrianglesCreated " << setw(9) << myTriangle.TrianglesCreated << endl;
    os << setw(20) << "TrianglesExisting " << setw(9) << myTriangle.TrianglesExisting << endl;
    os << setw(20) << "triangColour" << setw(9) << myTriangle.triangColour << endl;
    return os;
}

// aug 4
