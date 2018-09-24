//assign_3_12_fibonacciSequence.cpp
//A. Achimescu
//Ask the user for a number then determine if that num is in the Fibonacci Sequence

#include <iostream>
using namespace std;

bool isFiboncacci(double num);

int main()
{
    double num; //user might input a decimal number
    cout << "Please enter a number, then I will determine if that number is in the Fibonacci Sequence" << endl;
    cin >> num;
    cout << endl;

    if (isFiboncacci(num)) //if true, the num is in the sequence
        cout << endl << "That number is in the Fibonacci sequence." << endl;
    else //if false, the num is not in the sequence
        cout << endl << "That number was not in the sequence." << endl;
}

bool isFiboncacci(double num)
{
    bool sequence = false;
    int first = 1; //first number is 1
    int second = 1; //second num is 1
    int next = 0; //number after the one before; next number

    //if less than 1, not in the sequence; don't print first 2 terms
    if (num < 1)
        return sequence; //exit

    //print first 2 terms
    cout << "Term 1: " << first << endl; //insert first 2 nums & terms
    cout << "Term 2: " << second << endl;

    if (num == 1) //user defined num is in sequence; either term 1 or 2
    {
        sequence = true;
        return sequence; //exit
    }

     for (int i = 1; next <= num; i++)
     {
        next = first + second; //add the before 2 numbers to get the next num
        first = second; //2 nums before becomes 1 num before
        second = next; //1 num before becomes the next num (not including the addition of num before that)
        cout << "Term " << i+2 << ": "; //add 2 to i b/c first 2 terms were 1 and 1 (declared before)
        cout << next << endl;
        if (next == num) //user defined num is in sequence
        {
            sequence = true;
            return sequence; //exit
        }
    }
    //if not in Fibonacci
    return sequence;
}

//Tests

/*
Please enter a number, then I will determine if that number is in the Fibonacci
Sequence
6.7
Term 1: 1
Term 2: 1
Term 3: 2
Term 4: 3
Term 5: 5
Term 6: 8

That number was not in the sequence.

Process returned 0 (0x0)   execution time : 2.278 s
Press any key to continue.
*/

/*
Please enter a number, then I will determine if that number is in the Fibonacci
Sequence
34

Term 1: 1
Term 2: 1
Term 3: 2
Term 4: 3
Term 5: 5
Term 6: 8
Term 7: 13
Term 8: 21
Term 9: 34

That number is in the Fibonacci sequence.

Process returned 0 (0x0)   execution time : 2.966 s
Press any key to continue.
*/
