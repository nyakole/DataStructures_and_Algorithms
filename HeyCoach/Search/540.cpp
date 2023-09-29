// https://leetcode.com/problems/single-element-in-a-sorted-array
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (mid % 2 == 1)
        {
            mid--;
        }
        if (nums[mid] != nums[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 2;
        }
    }
    return nums[low];
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

    cout << "Output: " << singleNonDuplicate(nums) << endl;

    return 0;
}