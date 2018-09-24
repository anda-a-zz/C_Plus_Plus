//assign_3_14_wordDiamond.cpp
//A. Achimescu
//Ask the user for a single word then use those letters to draw out a diamond

#include <iostream>
using namespace std;
int main()
{
    int counter1 = 0; //counter for the top half of the diamond
    int a = 0; //general term for the bottom half of the diamond
    string word;
    bool wordCheck;

    do
    {
        wordCheck = true;
        cout << "Please enter a word." << endl;
        cin >> word;
        int len = word.length(); //length of word
        for (int i = 0; i < len; i++)
        {
            if (!(isalpha(word[i])))
                wordCheck = false;
        }
    } while (!wordCheck);


    int len = word.length(); //length of word

    //left side of diamond
    for (int col = 1; col <= len; col++) //exit after done half of diamond
    {
        int x = 0; //greatest first term for the right bottom side
        for (int row = 1 ; row <= len - col; row++) //blank rows
        {
            cout << " ";
        }
        cout << word[col-1]; //add an asterisk after the spaces

        if (counter1 != 0) //do not add any spaces for the top vertex
        {
            for (int space = 1; space <= (counter1* 2) - 1; space++) //space will be 2 times the counter, minus one
            {
                cout << " ";
                x++; //find the greatest first term
            }
            cout << word[col-1]; //asterisk after spaces
        }
        else //if counter = 0, do nothing
            ;
        cout << endl; //begin next line

        counter1++;
        a = x; //a- general term (to be remembered in another loop)
    }

    int counter2 = 0; //counter for the second half
    //bottom half of diamond
    for (int col2 = 1; col2 <= len ; col2++)
    {
        //left bottom side
        for (int row2 = 0 ; row2 <= col2 - 1; row2++)
        {
            cout << " ";
        }
        cout << word[len-counter2-2]; //writes the word backwards
        //right bottom side
        if (counter2 != len-2 )
        {
            for (int space = 1; space <= a + (counter2-1)*(-2) - 4; space++)
            {
                cout << " ";
            }
            cout << word[len-counter2-2]; //writes the word backwards
        }
        cout << endl;
        counter2++;
    }
    cout << endl;
    return 0;
}

//Tests

/*
Please enter a word.
diamond

      d
     i i
    a   a
   m     m
  o       o
 n         n
d           d
 n         n
  o       o
   m     m
    a   a
     i i
      d


Process returned 0 (0x0)   execution time : 2.605 s
Press any key to continue.
*/

/*
Please enter a word.
56jk23ik
Please enter a word.
&&&&&
Please enter a word.
triangle?
Please enter a word.
right
    r
   i i
  g   g
 h     h
t       t
 h     h
  g   g
   i i
    r



Process returned 0 (0x0)   execution time : 41.696 s
Press any key to continue.
*/
