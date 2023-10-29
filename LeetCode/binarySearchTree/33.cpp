// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int search(vector<int> &nums, int target)
{

    int n = nums.size();
    int low = 0;
    int high = n - 1;
    if (n == 1)
        return -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << " " << nums[mid] << endl;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
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

    cout << "Output: " << search(nums, 0) << endl;

    return 0;
}