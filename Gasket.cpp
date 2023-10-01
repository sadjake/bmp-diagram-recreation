#include "Gasket.h"
#include "Colour.h"

double GASKET_SIDE_TO_HEIGHT = 0.86666666;

// Default constructor
Gasket::Gasket()
{
	// initialize values
	sideLength = 100;
	xLocation = 0;
	yLocation = 0;
	iterations = 0;
	gasketColour = Colour(0, 0, 0, 255);
	lenSubTriList = 1;

	listOfSubTriangles = new Triangle[lenSubTriList];
	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
}

// Constructor with all argumements
Gasket::Gasket(int iterationsValue, int xLocationValue, int yLocationValue, int sideLengthValue, Colour gasketColourValue)
{
	// Initialize values based on constructor arguments
	iterations = iterationsValue;
	xLocation = xLocationValue;
	yLocation = yLocationValue;
	sideLength = sideLengthValue;

	if (!(xLocation >= 0 && xLocation < pageWidth && yLocation >= 0 && yLocation < pageLength)) {
		cout << "x position of Gasket object is off the page" << endl;
		cout << "x position and y position have been reset to 0" << endl;
		xLocation = 0;
		yLocation = 0;
	}

	//xLocation
	if (xLocation + sideLength > pageWidth) {
		int temp = sideLength - (xLocation + sideLength - pageWidth);
		cout << "scaling in x" << endl;
		cout << "sideLength was " << sideLength << " sideLength now is " << temp << endl;
		sideLength = temp;
	}

	//yLocation
	if (yLocation + GASKET_SIDE_TO_HEIGHT * sideLength > pageLength) {
		int temp = sideLength - (1 / GASKET_SIDE_TO_HEIGHT * (yLocation + GASKET_SIDE_TO_HEIGHT * sideLength - pageLength));
		cout << "scaling in y" << endl;
		cout << "sideLength was " << sideLength << " sideLength now is " << temp << endl;
		sideLength = temp;
	}

	// Initialize other attributes
	gasketColour = gasketColourValue;
	lenSubTriList = static_cast<int> (pow(3, iterations));
	listOfSubTriangles = new Triangle[lenSubTriList];
	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int i = 1; i <= iterations; i++) {
		GasketDivide(listOfSubTriangles, lenSubTriList / 3);
	}
}

// Copy constructor
Gasket::Gasket(const Gasket& toBeCopied)
{
	xLocation = toBeCopied.xLocation;
	yLocation = toBeCopied.yLocation;
	iterations = toBeCopied.iterations;
	sideLength = toBeCopied.sideLength;
	gasketColour = toBeCopied.gasketColour;
	lenSubTriList = toBeCopied.lenSubTriList;
	listOfSubTriangles = new Triangle[lenSubTriList];
	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int i = 0; i < lenSubTriList; i++) {
		listOfSubTriangles[i] = toBeCopied.listOfSubTriangles[i];
	}
}

// Destructor
Gasket::~Gasket()
{
	delete[] listOfSubTriangles; 
}

void Gasket::GasketDivide(Triangle* listOfSubTriangles, int trianglesIn)
{
	if (trianglesIn <= 0 || trianglesIn >= static_cast<int>(pow(3, iterations))) {
		cerr << " illegal number of triangle in Gasket Divide";
		exit(1);
	}
		
	else {
		for (int k = trianglesIn - 1; k >= 0; k--) {
			listOfSubTriangles[k].TriangleDivide(&listOfSubTriangles[k * 3]);
		}
	}
}


// Requested Get of accessors (Get functions)
// to Get the values of each of the
// variable members of the class Gasket

int Gasket::GetIterations() const
{
	return iterations;
}

int Gasket::GetXLocation() const
{
	return xLocation;
}

int Gasket::GetYLocation() const
{
	return yLocation;
}

int Gasket::GetSideLength() const
{
	return sideLength;
}

Colour Gasket::GetGasketColour() const
{
	return gasketColour;
}



// Requested Set functions to Set each of the variable members
// of class Gasket from outside of class Gasket.
// There is interaction between the members length width and area
// so Setting the variable member itself is not always adequate
// other calculations may be needded to maintain the consistancy
// of the instance of the class (the object)

void Gasket::SetXLocation(const int xLocationValue)
{
	xLocation = xLocationValue;

	if (!(xLocation >= 0 && xLocation < pageWidth && yLocation >= 0 && yLocation < pageLength)) {
		cout << "x position = " << xLocation << " and / or y position = " << yLocation << " of Triangle object is off the page" << endl;
		xLocation = 0;
		yLocation = 0;
		cout << "x position and y position have been reset to 0" << endl;
	}

	//xLocation
	if (xLocation + sideLength > pageWidth) {
		int temp = sideLength - (xLocation + sideLength - pageWidth);
		sideLength = temp;
	}

	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int k = 1; k <= iterations; k++) {
		GasketDivide(listOfSubTriangles, lenSubTriList / 3);
	}
}

void Gasket::SetYLocation(const int yLocationValue) {
	yLocation = yLocationValue;

	if (!(xLocation >= 0 && xLocation < pageWidth && yLocation >= 0 && yLocation < pageLength)) {
		cout << "x position = " << xLocation << " and / or y position = " << yLocation << " of Triangle object is off the page" << endl;
		xLocation = 0;
		yLocation = 0;
		cout << "x position and y position have been reset to 0" << endl;
	}

	//yLocation
	if (yLocation + GASKET_SIDE_TO_HEIGHT * sideLength > pageLength) {
		int temp = sideLength - (1 / GASKET_SIDE_TO_HEIGHT * (yLocation + GASKET_SIDE_TO_HEIGHT * sideLength - pageLength));
		sideLength = temp;
	}

	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int k = 1; k <= iterations; k++) {
		GasketDivide(listOfSubTriangles, lenSubTriList / 3);
	}
}

void Gasket::SetGasketColour(const Colour gasketColorValue)
{
	gasketColour = gasketColorValue;
	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int k = 1; k <= iterations; k++) {
		GasketDivide(listOfSubTriangles, lenSubTriList / 3);
	}
}

void Gasket::SetIterations(const int iterationsValue)
{
	iterations = iterationsValue;
	lenSubTriList = static_cast<int> (pow(3.0, iterations));
	delete[] listOfSubTriangles;
	listOfSubTriangles = NULL;
	listOfSubTriangles = new Triangle[lenSubTriList];
	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int k = 1; k <= iterations; k++) {
		GasketDivide(listOfSubTriangles, lenSubTriList / 3);
	}
}

void Gasket::SetSideLength(const int sideLengthValue)
{
	int height = 0;
	sideLength = sideLengthValue;

	if (sideLength < 1) {
		sideLength = 1;
	}
	
	if (xLocation + sideLength > pageWidth) {
		sideLength = pageWidth - xLocation;
	}

	height = static_cast<int> (sideLength * GASKET_SIDE_TO_HEIGHT);
	
	if (yLocation + height > pageLength) {
		sideLength = static_cast<int>((pageLength - yLocation) / GASKET_SIDE_TO_HEIGHT);
	}

	listOfSubTriangles[0] = Triangle(xLocation, yLocation, sideLength, gasketColour);
	
	for (int k = 1; k <= iterations; k++) {
		GasketDivide(listOfSubTriangles, lenSubTriList / 3);
	}
}

// display all the sub-triangles in the gasket
void Gasket::GasketDisplay(BMP& myImageValue, int thisIter, string theOutputFile)
{
	for (int i = 0; i < lenSubTriList; i++) {
		listOfSubTriangles[i].TriangleDisplay(myImageValue, theOutputFile);
	}
}

// print gasket attributes
void Gasket::GasketPrint() {
	cout << "iterations: " << iterations << endl;
	cout << "xLocation: " << xLocation << endl;
	cout << "yLocation: " << yLocation << endl;
	cout << "sideLength: " << sideLength << endl;
	cout << "gasketColour: " << gasketColour << endl;
	cout << "lenSubTriList: " << lenSubTriList << "\n" << endl;

	for (int k = lenSubTriList - 1; k >= 0; k--) {
		listOfSubTriangles[k].TrianglePrint();
	}
}

// aug h