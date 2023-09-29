// https://leetcode.com/problems/remove-element/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    int numofval = 0;
    int k = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            nums[numofval++] = nums[i];
        }
    }
    return numofval;
}
int main()
{
    int n;
    int target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    cin >> target;
    cout << "Output: " << removeElement(nums, target) << endl;

    return 0;
}