//assign_3_10_wordTriangle.cpp
//A. Achimescu
//Ask the user for a word, then output it as the sides of a triangle

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string word; //word input
    int len; //length of word

    cout << "Please enter a single word." << endl;
    cin >> word; //use cin statement to get a single word
    len = word.length(); //length of the word

    for (int i = 0 ; i <= len; i++) //create the spaces on the left side
    {
        for (int spaces1 = i ; spaces1 < len; spaces1++) //output spaces on left
            cout << "  ";

        for (int j = 0; j <= i; j++)
        {
            if (i == len)
            {
                for (int letter = 0; letter < len; letter++) //bottom side of triangle
                {
                    if (letter == len-1) //last letter on bottom line
                        cout << word [letter];
                    else //bottom line where word is outputed
                        cout << word [letter]<< " ";
                }
                cout << word [len-1];
                break;
            }
            else if (j == 0) //left side of triangle
                cout << word [len-i];
            else if (j == i) //right side of triangle
                cout << word [i-1];
            else
                cout << "  "; //blank space inside triangle
        }
        cout << endl;
    }
}

//Tests

/*
Please enter a single word.
spectacular

                    rs
                  a  p
                l    e
              u      c
            c        t
          a          a
        t            c
      c              u
    e                l
  p                  a
s p e c t a c u l a rr

Process returned 0 (0x0)   execution time : 16.952 s
Press any key to continue.
*/
