//assign_2_17_sameBirthday.cpp
//A. Achimescu
//The formula given states that in a room of n people, no 2 people can have the same birthday
//q = 365/365 * 364/365 * 363/365 * ... * (365-n+1)/365
//The probability of 2 people have the same birthday is determined by the formula p = 1 - q
//Find all the values for p of n from 2 to 70

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double q, p; //

    cout << "Number of People in the Room: \t\t Probability of at least 2 people" << endl;
    cout << "\t\t\t\t\t    having the same birthday:" << endl;
    for (int n = 2; n <= 70; n++) //number of people in the room
    {
        q = (365 - n + 1)/365.0; //start off the loop with the last num
        for (int i = 1; i <= n-1; i++) //fill in the formula; find i for the numerator
        {
            q = q* (365 - n + 1 + i)/365; //multiple each time the new q
        }

        p = 1 - q; //how many people have the same birthday
        if (n < 61)
            //print the number of people and the percentage of having the same birthday
            cout << "\t\t" << n << "\t\t\t\t" << setprecision(6) << p*100 << "%"<< endl;
        // if precision was set to 2
        //else //after 61, there is 100 percent of a chance that more than 1 person will have the same birthday
            //print out 100%
        //    cout << "\t\t" << n << "\t\t\t\t" << 100 << "%"<< endl;
    }
    return 0;
}


