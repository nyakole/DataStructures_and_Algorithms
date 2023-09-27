// https://leetcode.com/problems/regular-expression-matching/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstddef>
using namespace std;

bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string str;
    string str1;
    getline(cin, str);
    getline(cin, str1);
    cout << isMatch(str, str1);
    return 0;
}