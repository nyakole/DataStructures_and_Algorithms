// https://leetcode.com/problems/array-partition/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int> &nums)
{
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i = i + 2)
    {
        sum += nums[i];
    }
    return sum;
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

    int result = arrayPairSum(nums);
    cout << "Output: " << result << endl;
    return 0;
}