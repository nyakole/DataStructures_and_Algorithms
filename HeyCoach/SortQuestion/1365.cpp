// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] > nums[j] && i != j)
                count++;
        }
        ans.push_back(count);
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

    vector<int> ans = smallerNumbersThanCurrent(nums);

    cout << "Output: " << endl;

    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}