// https://leetcode.com/problems/contains-duplicate/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
   bool containsDuplicate(vector<int>& nums) {
         unordered_map<int, int> seen;
        for (int num : nums) {
            if (seen[num] >= 1)
                return true;
            seen[num]++;
        }
        return false;
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

    cout << "Output: " << containsDuplicate(nums) << endl;

    return 0;
}