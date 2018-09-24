//assign_4_4_readFile_firstChar.cpp
//A. Achimescu
//Ask the user for a text file then print the first character of each line

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string filename;
    ifstream infile;

    //Ask the user for a file
    cout << "Enter the input file name" << endl;
    getline(cin, filename);

    do
    {
        infile.open(filename.c_str(),ifstream::in); //open file

        if (!infile.is_open()) //if no such file, ask again
        {
            cout << "Could not open " << filename << endl; //error statement
            cout << "Enter anoher filename" << endl;
        }
        else //if can be opened, exit
            break;

        getline(cin,filename); //ask again if could not be opened before

    } while (true);

   //Find the first letter of each line
   int count = 0; //the number of the line
   cout << endl;
    while (infile.good())
    {
        count++; //add 1 to the line number
        string str;
        getline (infile, str); //find the strings inside the file
        bool alph = false; //make sure the first character is alphabetical

        int len = str.length(); //find the length of the string

        for (int i = 0; i < len; i++) //check entire file
        {
            if (isalpha(str[i])) //only print out alphabetical characters
            {
                alph = true;
                char val = str[i];
                val = toupper(val); //if not already, make character upper case
                cout << "First letter on line #" << count << ":\t" << val << endl; //output the first char on the line
                break; //exit
            }
        }
        if (!alph) //if not alphabetical, give error statement
        {
            alph = false;
            cout << "First letter on line #" << count << ":\tno alphabetical value" << endl;
        }
    }

    infile.close(); //close file
    return 0;
}

//Tests

/*
Enter the input file name
assign_4_4_input.txt

First letter on line #1:        I
First letter on line #2:        F
First letter on line #3:        F
First letter on line #4:        B
First letter on line #5:        F
First letter on line #6:        no alphabetical value
First letter on line #7:        no alphabetical value
First letter on line #8:        no alphabetical value
First letter on line #9:        no alphabetical value
First letter on line #10:       no alphabetical value
First letter on line #11:       no alphabetical value
First letter on line #12:       F
First letter on line #13:       B
First letter on line #14:       O
First letter on line #15:       B
First letter on line #16:       no alphabetical value
First letter on line #17:       O
First letter on line #18:       I
First letter on line #19:       no alphabetical value

Process returned 0 (0x0)   execution time : 17.518 s
Press any key to continue.
*/
