// https://leetcode.com/problems/reverse-words-in-a-string-iii
#include <iostream>
#include <string>
using namespace std;
string reverseWords(string str)
{
    int start = 0;
    for (int i = 0; i <= str.size(); i++)
    {

        // If the current word has ended
        if (str[i] == ' ' || i == str.size())
        {

            // Pointer to the last character
            // of the current word
            int end = i - 1;

            // Reverse the current word
            while (start < end)
            {
                swap(str[start], str[end]);
                start++;
                end--;
            }

            // Pointer to the first character
            // of the next word
            start = i + 1;
        }
    }
    return str;
}
int main()
{
    string str;
    getline(cin, str);
    cout << reverseWords(str);
    return 0;
}