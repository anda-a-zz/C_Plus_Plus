//assign_2_11_prime.cpp
//A. Achimescu
//Ask the user for an integer greater then 2, then find all the prime numbers leading up to that number

#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "Hello! I will write a list of prime numbers. Please enter the last " << endl;
    cout << "number you want me to go up to." << endl;
    cin >> num; //input last number from the prime list

    while (num < 2) //if num entered is less than 2, ask until num > 2
    {
        cout << "Please enter a number greater than 2." << endl;
        cin >> num; //receive input again
    }

    cout << "Prime Numbers: "; //Begin the list; will only appear once

    for (int factor = 2; factor <= num; factor++) //the first factor is 2, the last will be the number inputted
    {
        bool prime = true; //declare prime as true each time through the loop
        for (int divide = 2; divide * divide <= factor; divide++)
        {
            if (factor % divide == 0) //if is divisible; has factors
            {
                prime = false; //is false if can be divisible; not prime
                break;
            }
        }
        if (prime) //only print out if prime is true; not divisible
            cout << factor << " ";
    }
    return 0;
}

//Tests

/*
Hello! I will write a list of prime numbers. Please enter the last
number you want me to go up to.
100
Prime Numbers: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
Process returned 0 (0x0)   execution time : 3.635 s
Press any key to continue.
*/

/*
Hello! I will write a list of prime numbers. Please enter the last
number you want me to go up to.
-9
Please enter a number greater than 2.
0
Please enter a number greater than 2.
1
Please enter a number greater than 2.
-9000
Please enter a number greater than 2.
7
Prime Numbers: 2 3 5 7
Process returned 0 (0x0)   execution time : 11.944 s
Press any key to continue.
*/
