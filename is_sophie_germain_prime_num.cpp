//assign_3_17_sophieGermainPrime.cpp
//A. Achimescu
//A number is a Sophie Germain prime if both p and 2p + 1 are prime
//Ask the user for a number then print out all the Sophie Germain primes leading up to that number
//Remember to inclde the isPrime function

#include <iostream>
using namespace std;

bool isPrime (int num);
int positiveInt();

int main()
{
    int num = positiveInt(); //get a positive number
    cout << endl;

    for (int p = 1; p <= num ; p++)
    {
        long long sum = 2*p + 1; //sum of 2p + 1

        if (isPrime (p)) //check if p is prime
        {
            if (isPrime(sum)) //check if sum is prime if so is p
                //if prime, output 2p + 1, the sum, and saying its a Sophie Germain prime
                cout << "2 x " << p << " + 1 = " << sum << "\t\tSophie Germain prime." << endl;
        }
    }
    return 0;
}

int positiveInt()
{
    int num;
    double numCheck; //check if num is a positive int

    while (numCheck <= 0 || numCheck - num != 0) //loop until greater than 0 and and int
    {
        cout << "Please enter a positive integer: ";
        cin >> numCheck;
        num = numCheck;
    }
    return num;
}

bool isPrime (int num)
{
    bool prime = true;
    for (int divisor = 2; divisor < num; divisor++)
    {
        if (num % divisor == 0) //if divisible, num is not prime
        {
            prime = false;
            break;
        }
    }
    return prime;
}

//Tests

/*
Please enter a positive integer: 52

2 x 1 + 1 = 3           Sophie Germain prime.
2 x 2 + 1 = 5           Sophie Germain prime.
2 x 3 + 1 = 7           Sophie Germain prime.
2 x 5 + 1 = 11          Sophie Germain prime.
2 x 11 + 1 = 23         Sophie Germain prime.
2 x 23 + 1 = 47         Sophie Germain prime.
2 x 29 + 1 = 59         Sophie Germain prime.
2 x 41 + 1 = 83         Sophie Germain prime.

Process returned 0 (0x0)   execution time : 1.685 s
Press any key to continue.
*/

/*
Please enter a positive integer: 3.4
Please enter a positive integer: 0
Please enter a positive integer: 1

2 x 1 + 1 = 3           Sophie Germain prime.

Process returned 0 (0x0)   execution time : 16.993 s
Press any key to continue.
*/

/*
Please enter a positive integer: -2
Please enter a positive integer: 2

2 x 1 + 1 = 3           Sophie Germain prime.
2 x 2 + 1 = 5           Sophie Germain prime.

Process returned 0 (0x0)   execution time : 11.622 s
Press any key to continue.
*/
