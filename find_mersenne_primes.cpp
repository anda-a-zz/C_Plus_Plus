//assign_3_15_mersennePrimes.cpp
//A. Achimescu
//A Mersenne prime is a prime number of the form 2^n + 1, where n is a positive integer
//Ask the user for a value of n then display then list all the Mersenne primes to the user-defined integer
//To all the nums that aren't prime, display their factors

#include <iostream>
using namespace std;

void printFactors(int num);
int getPositiveInt();
bool isPrime(int num);

int main()
{
    int base = getPositiveInt(); //make sure num entered is a positive int
    cout << endl;

    for (int n = 1; n <= base; n++) //numbers 1 to the user defined int
    {
        cout << "n= " << n << endl; //output n
        long long product = 1; //begin at 1 so it multiplies nicely

        for (int i = 1; i <= n; i++) //2 to the power of n
            product = product * 2;

        product = product - 1; //end part of equation
        cout << "2^" << n << " - 1 = " << product << endl; //output the Mersenne num

        if (isPrime(product)) //Mersenne num is prime
        {
            cout << product << " is prime." << endl;
            cout << endl;
        }
        else //not prime; display the factors of the Mersenne num
        {
            cout << "Factors of " << product << ": ";
            printFactors(product);
            cout << endl << endl;
        }
    }
    return 0;
}

int getPositiveInt()
{
    double numCheck = 0; //check if num inputted was a whole num
    int num;

    while (numCheck <= 0 || numCheck - num != 0) //stop looping when num inputted is a positive whole int
    {
        cout << "Hello! Please enter a positive integer: ";
        cin >> numCheck;
        num = numCheck;
    }
    return num;
}

void printFactors(int num)
{
    for (int i = 1; i <= num; ++i ) //1 and num are both divisors of num
    {
        if (num % i == 0) // only check for divisibility
            cout << i << " "; //print out factors
    }
}

bool isPrime (int num)
{
    bool prime = true;
	for (int divisor = 2; divisor < num; divisor++)
	{
		if (num % divisor == 0) //if is divisible, num is not a prime
		{
			prime = false;
			break;
		}
	}
    return prime;
}
