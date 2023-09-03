// https://leetcode.com/problems/unique-email-addresses/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int numUniqueEmails(vector<string> &emails)
{
    unordered_set<string> s;
    for (int i = 0; i < emails.size(); i++)
    {
        string str;
        bool flag = false;
        bool dot = true;
        bool afterDomaname = false;
        for (int j = 0; j < emails[i].size(); j++)
        {
            if (emails[i][j] == '+' && !afterDomaname)
            {
                flag = true;
                continue;
            }
            if (emails[i][j] == '@')
            {
                flag = false;
                dot = false;
                afterDomaname = true;
                str += emails[i][j];
            }
            else if (emails[i][j] == '.' && dot)
                continue;
            else if (!flag)
            {
                str += emails[i][j];
            }
        }
        cout << str << endl;
        s.insert(move(str));
    }
    return s.size();
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<string> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        getline(cin, nums[i]);
    }
    cout << numUniqueEmails(nums);
    return 0;
}