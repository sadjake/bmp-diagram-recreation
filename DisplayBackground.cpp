#include "DisplayBackground.h"

void InitBackground(BMP& myImageValue, Colour backgroundColor,
                       int pageWidth, int pageLength)
{
    int i;
    int j;
    int bitWidth;
    int bitHeight;

    myImageValue.SetSize(pageWidth, pageLength);
    bitWidth = myImageValue.TellWidth();
    bitHeight = myImageValue.TellHeight();

    //(xlocation to xlocation+width) (ylocation to ylocation + height)
    for(i=0; i<bitWidth; i++)
    {
        for (j=0; j<bitHeight; j++)
        {
            myImageValue(i,j)->Red = backgroundColor.GetRedNumber();
            myImageValue(i,j)->Blue = backgroundColor.GetBlueNumber();
            myImageValue(i,j)->Green = backgroundColor.GetGreenNumber();
            myImageValue(i,j)->Alpha = backgroundColor.GetAlphaNumber();
        }
    }
}

void ResetBackground(BMP& myImageValue, Colour backgroundColor,
                       int pageWidth, int pageLength)
{
    int i;
    int j;


    //(xlocation to xlocation+width) (ylocation to ylocation + height)
	//set all pixels in  the bitmap to the background colour
    for(i=0; i<pageWidth; i++)
    {
        for (j=0; j<pageLength; j++)
        {
            myImageValue(i,j)->Red = backgroundColor.GetRedNumber();
            myImageValue(i,j)->Blue = backgroundColor.GetBlueNumber();
            myImageValue(i,j)->Green = backgroundColor.GetGreenNumber();
            myImageValue(i,j)->Alpha = backgroundColor.GetAlphaNumber();
        }
    }
}