// https://leetcode.com/problems/to-lower-case/submissions/1032991181/
#include <iostream>
using namespace std;
string toLowerCase(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // checking for uppercase characters
            str[i] = str[i] + 32;           // converting uppercase to lowercase
    }
    return str;
}
int main()
{
    string str;
    cin >> str;
    cout << toLowerCase(str);

    return 0;
}
