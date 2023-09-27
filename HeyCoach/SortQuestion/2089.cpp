// https://leetcode.com/problems/find-target-indices-after-sorting-array/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> targetIndices(vector<int> &nums, int target)
{
    vector<int> ans;
    if (nums.size() == 0)
        return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            ans.push_back(i);
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

    vector<int> ans = targetIndices(nums, 3);

    cout << "Output: " << endl;

    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}