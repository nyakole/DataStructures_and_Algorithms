// https://leetcode.com/problems/find-peak-element/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int findPeakElement(vector<int> &nums)
{

    int n = nums.size();
    int left = 0;
    int right = n - 1;
    if (n == 1)
        return 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if ((mid == (n - 1) || nums[mid] > nums[mid + 1]) && (mid == 0 || nums[mid] > nums[mid - 1]))
        {
            return mid;
        }
        else if (mid == 0 || nums[mid - 1] < nums[mid])
            left = mid + 1;

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

    cout << "Output: " << findPeakElement(nums) << endl;

    return 0;
}