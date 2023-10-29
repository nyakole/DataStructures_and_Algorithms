// https://leetcode.com/problems/wildcard-matching/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstddef>
using namespace std;

bool isMatch(string s, string p)
{
     vector<bool> dp(p.size() + 1, false);
        dp[0] = true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[j + 1] = true;
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            dp[0] = false;
            bool neighborLastRow = i == 1;
            for (int j = 1; j <= p.size(); ++j) {
                bool currLastRow = dp[j];
                if (p[j - 1] == '*') {
                    dp[j] = currLastRow || dp[j - 1];
                } else {
                    dp[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && neighborLastRow;
                }
                neighborLastRow = currLastRow;
            }
        }

        return dp[p.size()];
}

int main()
{
    string str;
    string str1;
    getline(cin, str);
    cout<<"enter second string";
    getline(cin, str1);
    cout << isMatch(str, str1);
    return 0;
}