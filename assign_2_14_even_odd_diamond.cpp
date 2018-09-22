//assign_2_14_even_odd_diamond.cpp
//A. Achimescu
//Ask the user for a number, then print out a diamond with that many number of lines
//Use asterisks to print out the hollow diamond.

#include <iostream>
using namespace std;

int main()
{
    int numlines;
    double numlinesCheck;
    int counter1 = 0; //counter for the top half of the diamond
    int a = 0; //general term for the bottom half of the diamond
    cout << "Please enter an integer greater than 3: ";
    cin >> numlinesCheck; //number of lines in the diamond
    numlines = numlinesCheck;

    while (numlines < 3 || numlinesCheck - numlines != 0 ) //if numlines is less than 3
    {
        cout << "Please enter an integer greater than 3: ";
        cin >> numlinesCheck;
        numlines = numlinesCheck;
    }

    cout << endl;
    //left side of diamond
    for (int col = 1; col <= (numlines - 1)/2 + 1; col++) //exit after done half of diamond
    {
        int x = 0; //greatest first term for the right bottom side
        for (int row = 1 ; row <= (numlines - 1)/2 + 1 - col; row++) //blank rows
        {
            cout << " ";
        }
        cout << "*"; //add an asterisk after the spaces

        if (counter1 != 0) //do not add any spaces for the top vertex
        {
            for (int space = 1; space <= (counter1* 2) - 1; space++) //space will be 2 times the counter, minus one
            {
                cout << " ";
                x++; //find the greatest first term
            }
            cout << "*"; //asterisk after spaces
        }
        else //if counter = 0, do nothing
            ;
        cout << endl; //begin next line

        counter1++;
        a = x; //a- general term (to be remembered in another loop)
    }

    //if numlines is even
    if (numlines % 2 == 0)
    {
        int counter2 = 0;
        //bottom half of diamond
        for (int col2 = 1; col2 <= (numlines - 1)/2 + 1; col2++) //exit once done second half of diamond
        {
            //left bottom side
            for (int row2 = 1 ; row2 <= col2 - 1; row2++)
            {
                cout << " ";
            }
            cout << "*";
            //right bottom side
            if (counter2 != (numlines - 1) / 2)
            {
                for (int space = 1; space <= a +(counter2-1)*(-2) - 2 ; space++)
                {
                    cout << " ";
                }
                cout << "*";
            }
            else
                ;
            cout << endl;
            counter2++;
        }
    }

    //if numlines is odd
    else
    {
        int counter2 = 0; //counter for the second half
        //bottom half of diamond
        for (int col2 = 1; col2 <= (numlines - 1)/2; col2++)
        {
            //left bottom side
            for (int row2 = 0 ; row2 <= col2 - 1; row2++)
            {
                cout << " ";
            }
            cout << "*";
            //right bottom side
            if (counter2 != (numlines - 1) / 2 - 1)
            {
                for (int space = 1; space <= a + (counter2-1)*(-2) - 4; space++)
                {
                    cout << " ";
                }
                cout << "*";
            }
            else
                ;
            cout << endl;
            counter2++;
        }
    }
}

//Tests
/*
Please enter an integer greater than 3: 16
       *
      * *
     *   *
    *     *
   *       *
  *         *
 *           *
*             *
*             *
 *           *
  *         *
   *       *
    *     *
     *   *
      * *
       *

Process returned 0 (0x0)   execution time : 4.608 s
Press any key to continue.
*/

/*
Please enter an integer greater than 3: 17
        *
       * *
      *   *
     *     *
    *       *
   *         *
  *           *
 *             *
*               *
 *             *
  *           *
   *         *
    *       *
     *     *
      *   *
       * *
        *

Process returned 0 (0x0)   execution time : 1.899 s
Press any key to continue.
*/

/*
Please enter an integer greater than 3: 2
Please enter an integer greater than 3: 1
Please enter an integer greater than 3: 0
Please enter an integer greater than 3: -4
Please enter an integer greater than 3: 3

 *
* *
 *

Process returned 0 (0x0)   execution time : 10.113 s
Press any key to continue.
*/

/*
Please enter an integer greater than 3: 6.7
Please enter an integer greater than 3: 4.5
Please enter an integer greater than 3: 2
Please enter an integer greater than 3: 0
Please enter an integer greater than 3: -3
Please enter an integer greater than 3: -5
Please enter an integer greater than 3: 9

    *
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    *

Process returned 0 (0x0)   execution time : 10.758 s
Press any key to continue.
*/
