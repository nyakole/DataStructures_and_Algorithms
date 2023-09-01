//https://leetcode.com/problems/peak-index-in-a-mountain-array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* int peakIndexInMountainArray(vector<int> &arr)
{
    int maxindex = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[maxindex] < arr[i])
        {
            maxindex = i;
        }
    }
    return maxindex;
} */
int peakIndexInMountainArray(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
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

    int result = peakIndexInMountainArray(nums);
    cout << "Output: " << result << endl;
    return 0;
}