//assign_3_9_factors.cpp
//A. Achimescu
//Display all the factors for any given number

#include <iostream>
using namespace std;

int postiveInt();
void printFactors(int num);

int main()
{
    int num = postiveInt(); //get a positive int
    cout << endl;

    cout << "The factors of that number are: " << endl;
    printFactors(num); //output factors of user defined num
    cout << endl;

    return 0;
}

int postiveInt()
{
    int num;
    double numCheck = 0; //check if num is an int; start off with 0 so it goes in loop

	while (numCheck - num != 0 || numCheck <= 1) //get another num if not int or greater than 2
    {
        cout << "Please enter a positive integer greater than 1." << endl;
        cin >> numCheck; //input another value
        num = numCheck;
    }
    return num;
}

void printFactors(int num)
{
    for (int i = 1; i <= num; ++i ) //1 and num are both divisors of num; find other divisors
    {
        if (num % i == 0) // only check for divisibility
            cout << i << " "; //output divisors
    }
}

//Tests

/*
Please enter a positive integer greater than 1.
0
Please enter a positive integer greater than 1.
1
Please enter a positive integer greater than 1.
-9
Please enter a positive integer greater than 1.
6

The factors of that number are:
1 2 3 6

Process returned 0 (0x0)   execution time : 5.753 s
Press any key to continue.
*/
