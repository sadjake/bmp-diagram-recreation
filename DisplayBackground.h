#ifndef DisplayFlag
#define DisplayFlag

#include "EasyBMP.h"
#include "Colour.h"
void InitBackground(BMP& myImageValue, Colour backgroundColor,
                       int pageWidth, int pageLength);
void ResetBackground(BMP& myImageValue, Colour backgroundColor,
                       int pageWidth, int pageLength);
#endif