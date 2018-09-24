//assign_4_5_fileInReverseOrder.cpp
//A. Achimescu
//Ask the user for a text file then open and read the contents of the file
//Afterwards, display the text to the screen in the reverse order to the file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string infilename;
    ifstream infile;

    //Ask the user for a file
    cout << "Please enter the input filename:" << endl;
    getline (cin,infilename);

    do
    {
        infile.open(infilename.c_str(), ifstream::in); //open file

        if (!infile.is_open()) //if no such file, ask again
        {
            cout << endl << "Could not open " << infilename << endl; //error statement
            cout << "Please enter anoher filename:" << endl;
        }
        else
            break; //if can be opened, exit

        getline(cin,infilename); //ask again if could not be opened before
    } while(true);

    vector <string> inWords; //create array of the strings in file

    while(infile.good()) //input all the contents from the file into the array
    {
        string str;
        infile >> str;
        inWords.push_back(str);
    }

    infile.close(); //close file
    for(int i = inWords.size()-1; i >= 0; i--) //output the array in reverse array
    {
        string str = inWords[i];
        cout << str << endl;
    }
    return 0;
}
