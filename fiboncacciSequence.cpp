//assign_2_12_fiboncacciSequence.cpp
//A. Achimescu
//Ask the user for the number of terms to be displayed in the Fibonacci sequence

#include <iostream>

using namespace std;

int main()
{
    int input;
    int first = 1; //first number is 1
    int second = 1; //second number is 2
    int next; //the next number in the sequence

    cout << "Enter the number of terms you want to be displayed in the" << endl;
    cout << "Fibonacci sequence. Greatest number you can enter is 46." << endl;
    cin >> input; //get num of terms

    while (input < 0 || input > 46)
    {
        cout << "Please enter a valid number" << endl;
        cin >> input;
    }

    cout << "Fibonacci Series:\n" << first << " " << second << " "; //output term1 & term2

    while (input != 2 ) //first 2 terms were already inputted
    {
        next = first + second; //add the before 2 numbers to get the next num
        cout << next << " "; //output the terms after term2
        first = second; //
        second = next;
        input--; //subtract 1 until the loop looped 7 times
    }
    cout << endl;
    return 0;
}

//Tests

/*
Enter the number of terms you want to be displayed in the
Fibonacci sequence.
-5
Please enter a valid number
4
Fibonacci Series: 1 1 2 3

Process returned 0 (0x0)   execution time : 3.165 s
Press any key to continue.
*/
