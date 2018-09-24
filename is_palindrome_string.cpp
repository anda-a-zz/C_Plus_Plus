//assign_3_16_palindromeStrings.cpp
//A. Achimescu
//Ask the user for a string, then figure out if it was a palindrome
//Do not include spaces, punctuation or anything non-alphabetical (including capitals)
//Create a bool function that determines if it is a pali or not

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(string text);

int main()
{
    string text;

    //tell user a bit about what the code will do
    cout << "Please enter a sentence or a word, hit enter when you are done." << endl;
    cout << "Hint: This program sees if what you wrote is the same word written" << endl;
    cout << "backwords and forwards, if it's a palindrome or not." << endl;
    getline(cin,text);

    if (isPalindrome(text)) //if true, string is the same forwards and backwards
        cout << endl << "That string is a palindrome." << endl;
    else //if false, it is not a palindrome
        cout << endl <<"That string is not a palindrome." << endl;

    return 0;
}

bool isPalindrome(string text)
{
    bool palindrome = true;
    int len = text.size();
    string c = ""; //second duplicated string
    int leng = text.length(); //length of string

    //take out anything that isn't alphabetical, and capitals
    for (int i = 0; i < len; i++)
    {
        if (!(islower(text[i]))) //change any capitals to lowercase
            text[i] = tolower(text[i]);

        if (isspace(text[i])) //take out any spaces
        {
            text.erase(i--, 1);
            len = text.size();
        }

        if (!(isalpha(text[i]))) //take out anything not alphabetical
        {
            text.erase(i--, 1);
            len = text.size();
        }
    }

    for (int j = leng - 1; j >= 0; j--) //reverse the order of the string into for another string
    {
        if (isalpha(text[j])) //only change if is alphabetical
            c += text[j]; //second reversed string
    }

    cout << endl;
    cout << "New word: \t" << text << endl << "Word reversed: \t" << c << endl;
    if (text != c) //if they are not the same, then it is not a palindrome
        palindrome = false;

    return palindrome;
}

//Tests

/*
Please enter a sentence or a word, hit enter when you are done.
Hint: This program sees if what you wrote is the same word written
backwords and forwards, if it's a palindrome or not.
taco cat

New word:       tacocat
Word reversed:  tacocat

That string is a palindrome.

Process returned 0 (0x0)   execution time : 3.278 s
Press any key to continue.
*/
/*
Please enter a sentence or a word, hit enter when you are done.
Hint: This program sees if what you wrote is the same word written
backwords and forwards, if it's a palindrome or not.
Was it a car or a cat I saw?

New word:       wasitacaroracatisaw
Word reversed:  wasitacaroracatisaw

That string is a palindrome.

Process returned 0 (0x0)   execution time : 12.251 s
Press any key to continue.
*/
