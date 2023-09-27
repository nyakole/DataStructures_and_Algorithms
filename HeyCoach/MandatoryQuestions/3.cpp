// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxLength = 0;
    vector<int> charIndex(128, -1);
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (charIndex[s[right]] >= left)
        {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
int main()
{
    string str;
    getline(cin, str);
    cout << lengthOfLongestSubstring(str);
    return 0;
}