// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int minPairSum(vector<int> &nums)
{
    int ans = INT_MIN;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() / 2; i++)
    {
        int sum = nums[i] + nums[nums.size() - 1 - i];
        ans = max(ans, sum);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << "Output: " << minPairSum(nums) << endl;

    return 0;
}