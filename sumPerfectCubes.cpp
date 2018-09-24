//assign_2_13_sumPerfectCubes.cpp
//A. Achimescu
//216 is the smallest of a sum of a perfect cube (216 = 6^3 = 3^3 + 4^3 + 5^3)
//Ask the user for an int, then find how many sum of cubes there are under that num

#include <iostream>
using namespace std;

int main()
{
    int num; //number inputted by user
    double numCheck; //if number inputted is an int
    int i = 1, j = 1, k = 1; //declare variables ahead
    int check = 1; //if user inputer a num greater than 216

    cout << "The lowest sum of cubes is 216. Please enter an integer. For a longer list," << endl;
    cout << "please enter a larger integer: "; //inform user about the first sum of cubes
    cin >> numCheck; //check if num is an int
    num = numCheck; //int num is equal to double num

    while (num < 1 || numCheck - num != 0) //if not greater than 1, write an error statement
    {
        cout << "Please enter a postive whole integer: ";
        cin >> numCheck; //re input number
        num = numCheck;
    }

    cout << endl;
    cout << "These are the perfect cubes found from 1 to " << num << ":" << endl; //title of list

    for (int i = 1; i*i*i + j*j*j + k*k*k <= num; i++) //first num; exit when it finally equals the sum of a perfect cube; equal to num
    {
       for (int j = i; i*i*i + j*j*j + k*k*k <= num; j++) //second num
       {
           for (int k = j; i*i*i + j*j*j + k*k*k <= num; k++) //third num
           {
               int perfectCube = i*i*i + j*j*j + k*k*k; //Easier to write the sum

                /* Perfect Cubes, but not sum
                cout << perfectCube << "\t = ";
                cout << i << "^3 + ";
                cout << j << "^3 + ";
                cout << k << "^3";
                cout << endl;
                */

               for (int x = 1; x*x*x <= perfectCube; x++) //
               {
                   if (x*x*x == perfectCube)
                   {
                        cout << perfectCube << "\t\t = "; //output the cubed num
                        cout << x << "^3" << "\t\t = "; //output x cubed that is equal to perfect cube
                        cout << i << "^3 + "; //output of 3 cubed num that their sum is equal to perfect cube
                        cout << j << "^3 + ";
                        cout << k << "^3";
                        cout << endl;
                        check++; //check to see how many times perfect cube was outputed
                   }
               }

           }
       }
    }
    if (check == 1) //if the num entered was less than 216
        cout << "You did not enter a number greater than 216." << endl;

    return 0;
}

//Tests

/*
The lowest sum of cubes is 216. Please enter an integer. For a longer list,
please enter a larger integer: -6
Please enter a postive whole integer: 0
Please enter a postive whole integer: 1

These are the perfect cubes found from 1 to 1:
You did not enter a number greater than 216.

Process returned 0 (0x0)   execution time : 4.887 s
Press any key to continue.
*/

/*
The lowest sum of cubes is 216. Please enter an integer. For a longer list,
please enter a larger integer: 654657

These are the perfect cubes found from 1 to 654657:
729              = 9^3           = 1^3 + 6^3 + 8^3
5832             = 18^3          = 2^3 + 12^3 + 16^3
68921            = 41^3          = 2^3 + 17^3 + 40^3
216              = 6^3           = 3^3 + 4^3 + 5^3
6859             = 19^3          = 3^3 + 10^3 + 18^3
19683            = 27^3          = 3^3 + 18^3 + 24^3
97336            = 46^3          = 3^3 + 36^3 + 37^3
15625            = 25^3          = 4^3 + 17^3 + 22^3
46656            = 36^3          = 4^3 + 24^3 + 32^3
551368           = 82^3          = 4^3 + 34^3 + 80^3
91125            = 45^3          = 5^3 + 30^3 + 40^3
1728             = 12^3          = 6^3 + 8^3 + 10^3
54872            = 38^3          = 6^3 + 20^3 + 36^3
68921            = 41^3          = 6^3 + 32^3 + 33^3
157464           = 54^3          = 6^3 + 36^3 + 48^3
8000             = 20^3          = 7^3 + 14^3 + 17^3
250047           = 63^3          = 7^3 + 42^3 + 56^3
343000           = 70^3          = 7^3 + 54^3 + 57^3
125000           = 50^3          = 8^3 + 34^3 + 44^3
373248           = 72^3          = 8^3 + 48^3 + 64^3
5832             = 18^3          = 9^3 + 12^3 + 15^3
185193           = 57^3          = 9^3 + 30^3 + 54^3
531441           = 81^3          = 9^3 + 54^3 + 72^3
24389            = 29^3          = 11^3 + 15^3 + 27^3
13824            = 24^3          = 12^3 + 16^3 + 20^3
157464           = 54^3          = 12^3 + 19^3 + 53^3
438976           = 76^3          = 12^3 + 40^3 + 72^3
421875           = 75^3          = 12^3 + 51^3 + 66^3
551368           = 82^3          = 12^3 + 64^3 + 66^3
357911           = 71^3          = 14^3 + 23^3 + 70^3
64000            = 40^3          = 14^3 + 28^3 + 34^3
27000            = 30^3          = 15^3 + 20^3 + 25^3
195112           = 58^3          = 15^3 + 42^3 + 49^3
85184            = 44^3          = 16^3 + 23^3 + 41^3
21952            = 28^3          = 18^3 + 19^3 + 21^3
46656            = 36^3          = 18^3 + 24^3 + 30^3
551368           = 82^3          = 19^3 + 60^3 + 69^3
74088            = 42^3          = 21^3 + 28^3 + 35^3
216000           = 60^3          = 21^3 + 42^3 + 51^3
195112           = 58^3          = 22^3 + 30^3 + 54^3
300763           = 67^3          = 22^3 + 51^3 + 54^3
110592           = 48^3          = 24^3 + 32^3 + 40^3
531441           = 81^3          = 25^3 + 48^3 + 74^3
97336            = 46^3          = 27^3 + 30^3 + 37^3
157464           = 54^3          = 27^3 + 36^3 + 45^3
592704           = 84^3          = 28^3 + 53^3 + 75^3
512000           = 80^3          = 28^3 + 56^3 + 68^3
148877           = 53^3          = 29^3 + 34^3 + 44^3
216000           = 60^3          = 30^3 + 40^3 + 50^3
438976           = 76^3          = 31^3 + 33^3 + 72^3
287496           = 66^3          = 33^3 + 44^3 + 55^3
373248           = 72^3          = 34^3 + 39^3 + 65^3
175616           = 56^3          = 36^3 + 38^3 + 42^3
328509           = 69^3          = 36^3 + 38^3 + 61^3
373248           = 72^3          = 36^3 + 48^3 + 60^3
421875           = 75^3          = 38^3 + 43^3 + 66^3
474552           = 78^3          = 39^3 + 52^3 + 65^3
592704           = 84^3          = 42^3 + 56^3 + 70^3
614125           = 85^3          = 50^3 + 61^3 + 64^3
592704           = 84^3          = 54^3 + 57^3 + 63^3

Process returned 0 (0x0)   execution time : 4.980 s
Press any key to continue.
*/

/*
The lowest sum of cubes is 216. Please enter an integer. For a longer list,
please enter a larger integer: 217

These are the perfect cubes found from 1 to 217:
216              = 6^3           = 3^3 + 4^3 + 5^3

Process returned 0 (0x0)   execution time : 1.529 s
Press any key to continue.
*/

/*
The lowest sum of cubes is 216. Please enter an integer. For a longer list,
please enter a larger integer: 7.8
Please enter a postive whole integer: 4.9
Please enter a postive whole integer: -3
Please enter a postive whole integer: 0
Please enter a postive whole integer: 1

These are the perfect cubes found from 1 to 1:
You did not enter a number greater than 216.

Process returned 0 (0x0)   execution time : 9.313 s
Press any key to continue.
*/
