#ifndef ColourFlag
#define ColourFlag

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "EasyBMP.h"
using namespace std;

const int pageWidth = 600;
const int pageLength = 800;
//nullptr = NULL;   //remove this line if you are using C++ 11 or newer compiler


class Colour
{
public:
    // constructors
    Colour();
    Colour( int red, int green, int blue, int alpha );
    Colour(const Colour& myColour);
    // mutators
    void SetRedNumber(int red);
    void SetBlueNumber( int blue);
    void SetGreenNumber( int green );
    void SetAlphaNumber( int alpha );
    // accessors
    int GetRedNumber() const;
    int GetBlueNumber() const;
    int GetGreenNumber() const;
    int GetAlphaNumber() const;
    //overloaded operators
    bool operator==(const Colour &Colour2) const;
    friend ostream& operator <<(ostream& os,
        const Colour& blockColor);
private:
    int redNumber;
    int blueNumber;
    int greenNumber;
    int alphaNumber;
};


#endif
