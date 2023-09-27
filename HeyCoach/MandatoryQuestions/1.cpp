// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) == mp.end())
            mp[nums[i]] = i;
        else
            return {mp[target - nums[i]], i};
    }

    return {-1, -1};
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

    vector<int> ans = twoSum(nums, 9);

    cout << "Output: " << endl;

    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}