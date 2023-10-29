// https://leetcode.com/problems/missing-number/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int allsum= n*(n+1)/2;
        return allsum-sum;
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

    cout << "Output: " << missingNumber(nums) << endl;

    return 0;
}