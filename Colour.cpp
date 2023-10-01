#include "Colour.h"

Colour::Colour()
{
    //default colour (should be grey)
    redNumber = 128;
    greenNumber = 128;
    blueNumber = 128;
    alphaNumber = 128;
}

Colour::Colour( int red, int green, int blue, int alpha)
{
    //Set to specified color
    redNumber = red;
    greenNumber = green;
    blueNumber = blue;
    alphaNumber = alpha;
}

Colour::Colour(const Colour& myColour)
{
    redNumber = myColour.redNumber;
    greenNumber = myColour.greenNumber;
    blueNumber = myColour.blueNumber;
    alphaNumber = myColour.alphaNumber;
}


ostream& operator << (ostream& os, const Colour& blockColor)
{
    os <<blockColor.alphaNumber<< "       ";
    os << blockColor.redNumber<<"  ";
    os << blockColor.greenNumber<<"  ";
    os <<blockColor.blueNumber<< "  ";
    return os;
}


void Colour::SetRedNumber(int red)
{
    //reSet the amount of red in the colour
    redNumber = red;
}

void Colour::SetGreenNumber(int green)
{
    //reSet the amount of green in the colour
    greenNumber = green;
}

void Colour::SetBlueNumber( int blue)
{
    //reSet the amount of blue in the colour
    blueNumber = blue;
}

void Colour::SetAlphaNumber( int alpha)
{
    alphaNumber = alpha;
}

int Colour::GetRedNumber() const
{
    return redNumber;
}

int Colour::GetGreenNumber() const
{
    return greenNumber;
}

int Colour::GetBlueNumber() const
{
    return blueNumber;
}

int Colour::GetAlphaNumber() const
{
    return alphaNumber;
}


bool Colour::operator==(const Colour &Colour2) const
{
    if ( redNumber	 == Colour2.redNumber  &&
        greenNumber == Colour2.greenNumber &&
        blueNumber	 == Colour2.blueNumber &&
        alphaNumber == Colour2.alphaNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
}


