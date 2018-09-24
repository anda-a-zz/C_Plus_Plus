//assign_3_13_binaryForm.cpp
//A. Achimescu
//Ask the user for a number then create the binary for that num

#include <iostream>
using namespace std;

void binary(int num);
int positiveInt ();

int main()
{
    int num = positiveInt(); //make sure num inputed is positive and an int

    cout << "The number " << num << " in binary form is ";
    binary(num); //output binary number

    cout << endl;
    return 0;
}

int positiveInt()
{
    double numCheck = 0; //check if num entered is a decimal
    int num;

    while (numCheck < 0 || numCheck - num != 0) //loop until num entered is positive (including 0) and is whole
    {
        cout << "Please enter a positive integer: ";
        cin >> numCheck;
        num = numCheck;
    }
    return num;
}

void binary(int num)
{
    long long remainder; //make long long so it can store more nums

    if (num <= 1) //last num output
    {
        cout << num; //last num
        return; //exit
    }
    remainder = num % 2; //to get a 1 or 0
    binary(num / 2); //recall function

    cout << remainder; //output 1 or 0
}

//Tests

/*
Please enter a positive integer: 0
The number 0 in binary form is 0

Process returned 0 (0x0)   execution time : 0.640 s
Press any key to continue.
*/

/*
Please enter a positive integer: -8
Please enter a positive integer: 5.6
Please enter a positive integer: 7
The number 7 in binary form is 111

Process returned 0 (0x0)   execution time : 19.302 s
Press any key to continue.
*/

/*
Please enter a positive integer: 3456645
The number 3456645 in binary form is 1101001011111010000101

Process returned 0 (0x0)   execution time : 2.123 s
Press any key to continue.
*/

/*
Please enter a positive integer: 6.7
Please enter a positive integer: 1
The number 1 in binary form is 1

Process returned 0 (0x0)   execution time : 15.712 s
Press any key to continue.
*/
