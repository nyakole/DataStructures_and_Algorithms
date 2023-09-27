// https://leetcode.com/problems/sort-array-by-parity/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sortArrayByParity(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            swap(nums[j], nums[i]);
            j++;
        }
    }
    return nums;
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

    vector<int> ans = sortArrayByParity(nums);

    cout << "Output: " << endl;

    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}