// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProductDifference(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int ans = (nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]);
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

    cout << "Output: " << maxProductDifference(nums) << endl;

    return 0;
}