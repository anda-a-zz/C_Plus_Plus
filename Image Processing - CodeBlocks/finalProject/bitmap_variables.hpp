//bitmap.hpp

#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>

///////////////FILE HEADER

struct BMPHeader
{
    unsigned short ID;          //signature - "BM" in numeral form
    unsigned int fileSize;      //size in bytes
    unsigned short reserved;   //reserved; must be 0
    unsigned int dataOffset;    //the offset in bytes from the BMPHeader to the bitmap bits
    //BMPHeader(): fileSize(0),  reserved1(0), reserved2(0), dataOffset(0) { }
};

//#define BF_TYPE 0x4D42             //BM

/////////////FILE INFO HEADER
struct infoHeader
{
    unsigned int    bmpSize;             //number of bytes required
    unsigned int    bmpWidth;            //width in pixels
    unsigned int    bmpHeight;           //height in pixels
                                            //if positive, it is a bottom-up DIB and its origin is the lower left corner
                                            //if negative, it is a top-down DIB and its origin is the upper left corner
    unsigned short  bmpPlanes;           //number of color planes; must be 1
    unsigned short  bmpBitCount;         //number of bit per pixel; must be 1, 4, 8, 16, 24, or 32
    unsigned int    bmpCompression;      //type of compression
    unsigned int    bmpSizeImage;        //size of image in bytes
    unsigned int    bmpXPelsPerMeter;    //number of pixels per meter in x axis
    unsigned int    bmpYPelsPerMeter;    //number of pixels per meter in y axis

    //both set to 256, while 16 and 24-bit images will set them to 0
    unsigned int    bmpClrUsed;          //number of colors used
    unsigned int    bmpClrImportant;     //number of colors that are important
};

struct pixels
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char reserved;
};


#endif


