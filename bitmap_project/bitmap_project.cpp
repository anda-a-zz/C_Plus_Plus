
//A. Achimescu
// This program will read a bitmap image and output it's header information onto the program window but have the colour information be intputed into a text file.
// Afterwards, the user can choose if they would like to give their image any effects (ie: sharpness, black and white, blur, etc.)

#include <iostream>
#include <string>
#include <fstream>      //to input the image
#include <sstream>      //convert string to int
#include <cstdio>       //fopen, fclose
#include <cctype>       //tolower()

#include "bitmap_variables.h"  //where the variables are
#include "CImg.h"                //for the image effects

using namespace std;
using namespace cimg_library; //to use the CImg library

//reading the bmp file
void HDR(ifstream &inputImage);
void IHDR(ifstream &inputImage);
unsigned char* pixelArray(char* filename, int width, int height);

//questions
bool answerYN();
void chooseEffect(char* filename);

//effects/fliters
void resizeBMP(char* filename);
void greyscaleBMP(char* filename);
void blurBMP(char* filename);
void sharpenBMP(char* filename);

//declare them now, so they don't have to be declared multiple times
BMPHeader hdr;
infoHeader ihdr;
pixels pix;

int main() {
    ifstream inputImage;    //bmp picture
    
    //Get the filename
    char filename[40];
    cout << "For a bitmap image," << endl << "Enter input filename: ";
    cin >> filename;
   
    //open picture 
    inputImage.open(filename, ios::in| ios::binary);
    
    //read the ID before continuing to read the entire file
    inputImage.read((char *)&hdr.ID , sizeof(unsigned short));
    
    //if the file is not found, give an error message & ask the user to input the file name again
    while (inputImage.is_open() == false){
        cout << "File not found, input filename again: " ;
        cin >> filename;
        inputImage.open(filename, ios::in | ios::binary);
        inputImage.read((char *)&hdr.ID , sizeof(unsigned short));
    }
    //if the ID is not 19778 (which is the same as .bmp) then give an error message
    if (hdr.ID != 19778) {
        cout << "The file entered was not a pure BMP file." << endl;
        return 0;
    }
    
    //Output the info from the headers
    HDR(inputImage);    //header info
    IHDR(inputImage);   //info header info
    
    //In an existing text file, all the colours from the image will be stored inside
    unsigned char* data = pixelArray(filename, ihdr.bmpWidth, ihdr.bmpHeight); //pixel array
    
    //Ask the user to choose some colour effects
    chooseEffect(filename);
    
    //close the bmp
    inputImage.close();
    
    //end the program
    cout << "Goodbye!" << endl;
    cout << "Program ended." << endl;
    return 0;
}

/////////////////////////FILE HEADER
void HDR(ifstream &inputImage) {
    //Read the rest of the header
    inputImage.read((char *)&hdr.fileSize , sizeof(unsigned int));
    inputImage.read((char *)&hdr.reserved , sizeof(unsigned int));
    inputImage.read((char *)&hdr.dataOffset , sizeof(unsigned int));
    
    //Display file header
    cout << endl;
    cout << "File Header" << endl;
    cout << "ID        : " << hdr.ID << endl;
    cout << "File Size : " << hdr.fileSize << " byte(s)" << endl;
    cout << "Reserved  : " << hdr.reserved << endl;
    cout << "Offset    : " << hdr.dataOffset << " byte(s)" << endl;
}

/////////////////////////INFO FILE HEADER
void IHDR(ifstream &inputImage) {
    // Read info header
    inputImage.read((char *)&ihdr.bmpSize, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpWidth, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpHeight, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpPlanes, sizeof(unsigned short));
    inputImage.read((char *)&ihdr.bmpBitCount, sizeof(unsigned short));
    inputImage.read((char *)&ihdr.bmpCompression, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpSizeImage, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpXPelsPerMeter, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpYPelsPerMeter, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpClrUsed, sizeof(unsigned int));
    inputImage.read((char *)&ihdr.bmpClrImportant, sizeof(unsigned int));
    
    //Display info file header
    cout << endl;
    cout << "Info File Header"    << endl;
    cout << "Header Size      : " << ihdr.bmpSize << " byte(s)" << endl;
    cout << "Width            : " << ihdr.bmpWidth << " pixel(s)" << endl;
    cout << "Height           : " << ihdr.bmpHeight << " pixel(s)" << endl;
    cout << "Planes           : " << ihdr.bmpPlanes << endl;
    cout << "Bits Per Pixel   : " << ihdr.bmpBitCount << endl;
    cout << "Compression      : " << ihdr.bmpCompression << endl;
    cout << "Data Size        : " << ihdr.bmpSizeImage << " byte(s)" << endl;
    cout << "H Resolution     : " << ihdr.bmpXPelsPerMeter << endl;
    cout << "V Resolution     : " << ihdr.bmpYPelsPerMeter << endl;
    cout << "Used Colors      : " << ihdr.bmpClrUsed << endl;
    cout << "Important Colors : " << ihdr.bmpClrImportant << endl;
}

/////////////////////////PIXEL ARRAY
unsigned char* pixelArray(char* filename, int width, int height){
    ofstream colourFile;                                //text file
    
    FILE* f = fopen(filename, "rb");                    //open the picture
    colourFile.open ("Colours.txt");                    //open the text file
    
    int row_padded = (width*3 + 3) & (~3);              //pixel array padding
    unsigned char* data = new unsigned char[row_padded];//pixel array
    unsigned char tmp;                                  //data that will go into the array
    
    //output all the pixel data into the array & text file
    for (int i = 0; i < height; i++) {
        fread(data, sizeof(unsigned char), row_padded, f);
        for (int j = 0; j < width*3; j += 3) {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;
            
            //output all colours into a text file named Colours.txt
            colourFile << "R: " << (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2] << "\n";
        }
    }
    //tell the user where they can find the pixel array of their image
    cout << endl;
    cout << "You can find your pixel array of your image in Colours.txt" << endl;
    cout << endl;
    
    colourFile.close(); //close the text file
    return data;        //return the array of colours
}

/////////////////////////IS NUMERICAL?
bool isNumerical (string numberStr) {
    int size = numberStr.size(); //size of the string
    
    //read every letter to make sure there's no characters other than numbers
    for (int u = 0; u < size; u++) {
        //if number entered is alphabetical or not a digit, return a false value
        if (isdigit(numberStr[u]) == 0)
            return false;
    }
    //if string is numeric, return a true value
    return true;
}

/////////////////////////YES OR NO
bool answerYN() {
    string answer;  //what the user will say
    int size;       //the size of the answer
    
    //ask the user yes or no
    do {
        cout << "Yes or no?" << endl;
        cin >> answer;
        size = answer.size();
        for (int u = 0; u <= size; u++) //make all letters lowercase
            answer[u] = tolower(answer[u]);
        cout << endl;
    } while (answer != "no" && answer != "yes"); //exit when user says yes or no
    
    //if user says yes, return a true value
    //if user says no, return a false value
    return (answer == "yes" ? true : false);
}

/////////////////////////CHOOSE AN EFFECT
void chooseEffect(char* filename) {
    bool goodbye = true;//when to exit out of the loop
    int size;           //size of number string
    
    //exit when the the user goodbye= false
    while (goodbye) {
        int effect = 0;         //what number/effect the user would like to have
        string number = " ";      //when user chooses a number for the effect; user friendly
        
        //ask the user for any effects
        cout << "Would you like to do any effects on your image?" << endl;
        bool answer = answerYN();
        
        //if yes, give them a list of possible effects
        if (answer) {
            cout << "Please choose which effect you would like to use on your image." << endl;
            while (effect != 1 && effect != 2 && effect != 3 && effect != 4) {
                //list
                cout << "1. Resize my photo" << endl;
                cout << "2. Make my photo black and white" << endl;
                cout << "3. Make my picture blurry" << endl;
                cout << "4. Sharpen my image" << endl;
                cout << "5. Nevermind, I don't want an effect" << endl;
                cin >> number;
                
                //make all letters lowercase
                size = number.size();
                for (int u = 0; u <= size; u++) {
                    if (isalpha(number[u]))
                        number[u] = tolower(number[u]);
                }
                
                //convert string into an int
                stringstream ss(number);
                ss >> effect;
                
                //make sure the user's output was one of the options
                if (effect == 1 || number == "one" || number == "1.")
                    effect = 1;
                else if (effect == 2 || number == "two" || number == "2.")
                    effect = 2;
                else if (effect == 3 || number == "three" || number == "3.")
                    effect = 3;
                else if (effect == 4 || number == "four" || number == "4.")
                    effect = 4;
                else if (effect == 5 || number == "five" || number == "5.")
                    return;
                //if the answer was not valid, gives an error message and the loop starts again
                else
                    cout << "Please enter a number from the list" << endl << endl;
            }
            
            //after a valid amount has been entered, transport to the effect functions
            switch (effect) {
                case 1: resizeBMP(filename);
                    break;
                case 2: greyscaleBMP(filename);
                    break;
                case 3: blurBMP(filename);
                    break;
                case 4: sharpenBMP(filename);
                    break;
            }
        }
        //if no, close the program
        else
            goodbye = false;
    }
}

/////////////////////////RESIZE IMAGE
void resizeBMP (char* filename) {
    int width = 0, height = 0; //numerical w&h
    string widthStr, heightStr; //orginal answer w&h
    
    cout << endl;
    cout << "Please enter what size you want your image to be." << endl;
    
    //make sure number entered is positive
    do {
        cout << "Width: ";
        cin >> widthStr;
        
        //if a number, convert string into an int
        if (isNumerical(widthStr)) {
            stringstream ss(widthStr);
            ss >> width;
        }
        
        //if not a number, ask for the number again
        if (!isNumerical(widthStr) || width == 0)
            cout << "Please enter a positive number" << endl;
        
    } while (width <= 0);
    
    do {
        cout << "Height: ";
        cin >> heightStr;
        //if a number, convert string into an int
        if (isNumerical(heightStr)) {
            stringstream ss(heightStr);
            ss >> height;
        }
        
        //if not a number, ask for the number again
        if (!isNumerical(heightStr) || height == 0)
            cout << "Please enter a positive number" << endl;
        
    } while (height <= 0);
    
    CImg<unsigned char> image(filename); //have the library know what image it should resize
    image = image.resize(width, height); //modify image
    
    cout << endl;
    cout << "Would you like your image to be displayed?" << endl;
    bool answer = answerYN();
    
    if (answer) {
        CImgDisplay main_disp(image,"Image resized");
        cout << "Please exit the second new window when you want to continue." << endl;
        //wait until the user closes the pop up window
        while (!main_disp.is_closed() )
            main_disp.wait();
    }
    
    //asks user if they want to save their image
    cout << "Would you like to save your image?" << endl;
    answer = answerYN();
    
    //save the new image as resized.bmp if user says yes
    if (answer) {
        image.save("resized.bmp");
        cout << "Your image has been saved as resized.bmp" << endl;
    }
}

/////////////////////////CONVERT IMAGE TO GREYSCALE
void greyscaleBMP (char* filename) {
    CImg<unsigned char> image(filename), grayWeight(image.width(), image.height(), 1, 1, 0);
    
    // for all pixels x,y in image
    cimg_forXY(image,x,y) {
        // Separation of channels
        int R = (int)image(x,y,0,0);
        int G = (int)image(x,y,0,1);
        int B = (int)image(x,y,0,2);
        
        // Real weighted addition of channels for gray
        int grayValueWeight = (int)(0.299*R + 0.587*G + 0.114*B);
        // saving pÌxel values into image information
        grayWeight(x,y,0,0) = grayValueWeight;
    }
    cout << "Would you like your image to be displayed?" << endl;
    bool answer = answerYN();
    
    if (answer) {
        CImgDisplay draw_dispGrayW(grayWeight,"Black and White");
        cout << "Please exit the second new window when you want to continue." << endl;
        //wait until the user closes the pop up window
        while (!draw_dispGrayW.is_closed())
            draw_dispGrayW.wait();
    }
    
    //asks user if they want to save their image
    cout << "Would you like to save your image?" << endl;
    answer = answerYN();
    
    //save the new image as blackandwhite.bmp if user says yes
    if (answer) {
        grayWeight.save("blackandwhite.bmp");
        cout << "Your image has been saved as blackandwhite.bmp" << endl;
    }
}

/////////////////////////BLUR THE IMAGE
void blurBMP(char* filename) {
    string blurryStr;   //ask the user how blurry they would like to make their image
    int blurry = 0;         //making sure user's answer is valid
    
    CImg<unsigned char> image(filename), visu(500,400,1,3,0);
    
    //ask the user how much they would like to blur their image
    cout << "How blurry would you like your image to be?" << endl;
    
    //make sure the blurriness is a number
    do {
        cin >> blurryStr;
        //if a number, convert string into an int
        if (isNumerical(blurryStr)) {
            stringstream ss(blurryStr);
            ss >> blurry;
        }
        //if not a number, ask for the number again
        if (!isNumerical(blurryStr))
            cout << "Please enter a positive number" << endl;
            
        cout << endl;
    } while (blurry <= 0);
    
    image.blur(blurry); //blur the image
    
    //asks user if they want to save their image
    cout << "Would you like your image to be displayed?" << endl;
    bool answer = answerYN();
    
    //if yes, the picture will be displayed
    if (answer) {
        CImgDisplay main_disp(image,"Blurry");
        cout << "Please exit the second new window when you want to continue." << endl;
        //wait until the user closes the pop up window
        while (!main_disp.is_closed())
            main_disp.wait();
    }
    
    //asks user if they want to save their image
    cout << "Would you like to save your image?" << endl;
    answer = answerYN();
    
    //save the new image as blurry.bmp if user says yes
    if (answer) {
        image.save("blurry.bmp");
        cout << "Your image has been saved as blurry.bmp" << endl;
    }
}

/////////////////////////SHARPEN THE IMAGE
void sharpenBMP (char* filename) {
    CImg<unsigned char> image(filename); //open the image
    
    //sharpen the image
    image.sharpen(200.02f);
    
    //asks user if they want to save their image
    cout << "Would you like your image to be displayed?" << endl;
    bool answer = answerYN();
    
    //if yes, the picture will be displayed
    if (answer) {
        CImgDisplay image_disp(image,"Sharp");
        cout << "Please exit the second new window when you want to continue." << endl;
        //wait util the user closes the pop up window
        while (!image_disp.is_closed())
            image_disp.wait();
    }
    
    //asks user if they want to save their image
    cout << "Would you like to save your image?" << endl;
    answer = answerYN();
    
    //save the new image as sharpness.bmp if user says yes
    if (answer) {
        image.save("sharpness.bmp");
        cout << "Your image has been saved as sharpness.bmp" << endl;
    }
}

