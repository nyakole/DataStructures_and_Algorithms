// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int numofval = 1;
    int val = nums[0];
    int k = n - 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[numofval++] = nums[i];
            val = nums[i];
        }
    }
    return numofval;
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

    cout << "Output: " << removeDuplicates(nums) << endl;

    return 0;
}