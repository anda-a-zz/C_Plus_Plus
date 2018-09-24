//assign_3_8_isPrime.cpp
//A. Achimescu
//Ask the user for a number then find all the prime nums from 2 to the user defined num
//Create a function with the signature bool isPrime(int num)

#include <iostream>
using namespace std;

bool isPrime(int num);
int postiveInt();

int main()
{
	int num = postiveInt(); //get a positive int

    cout << endl;
	for (int i = 2; i <= num; i++) //all nums between 2 and user defined int
    {
        if (isPrime(i)) //if true, num is prime
            cout << i << "\t is prime" << endl;
        else //if false, num is divisible
            cout << i << "\t is incomposite" << endl;
    }
    return 0;
}

int postiveInt()
{
    int num;
    double numCheck = 0; //check if num is an int; start off with 0 so it goes in loop

	while (numCheck - num != 0 || numCheck <= 2) //get another num if not int or greater than 2
    {
        cout << "Please enter a positive integer greater than 2." << endl;
        cin >> numCheck;
        num = numCheck;
    }
    return num;
}


bool isPrime (int num)
{
    bool prime = true;
	for (int divisor = 2; divisor < num; divisor++) //dividors for the num
	{
		if (num % divisor == 0) //if a divisor is found, num is not prime
		{
			prime = false;
			break; //exit with a non prime num
		}
	}
    return prime; //got through the loop without finding a divisor
}

//Tests

/*
Please enter a positive integer greater than 2.
1
Please enter a positive integer greater than 2.
0
Please enter a positive integer greater than 2.
2
Please enter a positive integer greater than 2.
6.7
Please enter a positive integer greater than 2.
7

2        is prime
3        is prime
4        is incomposite
5        is prime
6        is incomposite
7        is prime

Process returned 0 (0x0)   execution time : 11.345 s
Press any key to continue.
*/

/*
Please enter a positive integer greater than 2.
67

2        is prime
3        is prime
4        is incomposite
5        is prime
6        is incomposite
7        is prime
8        is incomposite
9        is incomposite
10       is incomposite
11       is prime
12       is incomposite
13       is prime
14       is incomposite
15       is incomposite
16       is incomposite
17       is prime
18       is incomposite
19       is prime
20       is incomposite
21       is incomposite
22       is incomposite
23       is prime
24       is incomposite
25       is incomposite
26       is incomposite
27       is incomposite
28       is incomposite
29       is prime
30       is incomposite
31       is prime
32       is incomposite
33       is incomposite
34       is incomposite

Process returned 0 (0x0)   execution time : 0.737 s
Press any key to continue.
*/
