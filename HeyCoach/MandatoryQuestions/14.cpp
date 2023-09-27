// https://leetcode.com/problems/longest-common-prefix/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string> &v)
{
    string ans = "";
    sort(v.begin(), v.end());
    int n = v.size();
    string first = v[0], last = v[n - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<string> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n + 1; i++)
    {
        getline(cin, nums[i]);
    }
    cout << longestCommonPrefix(nums);
    return 0;
}