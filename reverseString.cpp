//assign_3_7_reverseSentence.cpp
//A. Achimescu
//Ask the user for a sentence, then output again in reverse order

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string even;
    int len;

    cout << "Hello! Please enter a string with an even amount of characters!" << endl;
    getline(cin,even); //get string
    len = even.length(); //get string amount

    while (len % 2 != 0) //continue to ask until string ha an even amount of chars
    {
       cout << "Please enter a string with an even amount of characters." << endl;
        getline(cin,even); //reinput the string
        len = even.length();
    }

    cout << endl;
    for (int i = len - 1; i >= 0; i--) //begin at the end of the string and end at the first letter
        cout << even[i]; //ouput string in reverse order

    cout << endl;
    return 0;
}

//Tests

/*
Hello! Please enter a string with an even amount of characters!
*1*2*3*4*5*6

6*5*4*3*2*1*

Process returned 0 (0x0)   execution time : 13.271 s
Press any key to continue.
*/

/*
Hello! Please enter a string with an even amount of characters!
i like chicken!!

!!nekcihc ekil i

Process returned 0 (0x0)   execution time : 14.459 s
Press any key to continue.
*/
