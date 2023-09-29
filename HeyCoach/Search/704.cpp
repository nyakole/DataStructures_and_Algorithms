// https://leetcode.com/problems/binary-search
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return -1;
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

    cout << "Output: " << search(nums, 2) << endl;

    return 0;
}