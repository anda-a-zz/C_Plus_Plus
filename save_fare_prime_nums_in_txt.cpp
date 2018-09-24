//assign_4_9_farePrimesOutFile.cpp
//A. Achimescu
//A Fare prime is when it's digits are rotated, all those options are still prime (ie: 197, 971 and 719)
//Ask the user for a numbe then find all the fare primes and save the results in a text file.

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool checkprime (long int num);
bool rounder(long int i);

int main()
{
    long int num;
    long count = 1;
    vector <int> farePrimes;

    cout << "A Fare prime is when it's digits are rotated, all those options are still prime" << endl;
    cout << "(ie: 197, 971 and 719). Please enter a number:" << endl;
    cin >> num;

    for (int k = 2; k <= num; k++)
    {
        if(rounder(k))
            farePrimes.push_back(k);
    }

    string outfilename;
    ofstream outfile;

    cout << "Thank you! Now please enter the file where you would like to store this" << endl;
    cout << "information" << endl;
    getline(cin,outfilename);

    do
    {
        outfile.open(outfilename.c_str(), ofstream::out); //open file
        if (!outfile.is_open()) //if could not open, give an error statement
        {
            cout << "Could not open " << outfilename << endl;
            cout << "Enter anoher filename" << endl;
        }
        else
            break; //if was able to be opened, exit

        getline(cin,outfilename); //ask for file again if not opened
    } while(true);

    for(int i = 1; i <= farePrimes.size(); i++)
    {
        int fareP = farePrimes[i];
        outfile << fareP << endl;
    }

    outfile.close(); //close file

    cout << "Done! Go check your file!" << endl;

    return 0;
}

bool checkprime (long int num)
{
    if (num <= 1)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;

        int upperLimit = sqrt(num) +1;

        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                return false;
            divisor += 2;
        }
        return prime;
    }
}

bool rounder(long int i)
{
    long int dup1, dup2;
    int k, flag = 0;
    dup1 = dup2 = i;
    if(checkprime(i))
    {
        do
        {
            flag = 0;
            k = 1;
            dup1 = dup2;

            while(dup1 > 9)
            {
                if(dup1 % 10 == 0)
                    flag = 1;
                dup1 /= 10;
                k *= 10;
            }

            dup2=((dup2%k)*10) + dup1;

            if(!checkprime(dup2))
                return false;
        }while(dup2 != i && flag == 0);

        if(flag == 1)
            return false;
        else
            return true;
    }
    else
        return false;
}

//Tests
/*
A Fare prime is when it's digits are rotated, all those options are still prime
(ie: 197, 971 and 719). Please enter a number:
200
Thank you! Now please enter the file where you would like to store this
information
assign_4_9_input.txt
Done! Go check your file!

Process returned 0 (0x0)   execution time : 27.872 s
Press any key to continue.

*/
