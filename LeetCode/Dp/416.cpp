// https://leetcode.com/problems/partition-equal-subset-sum/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool ispresent(int ind, vector<int> &nums, int target)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return nums[ind] == target;
    // sum+=nums[ind];
    bool nottaken = ispresent(ind - 1, nums, target);
    bool taken = false;
    if (nums[ind] >= target)
        taken = ispresent(ind - 1, nums, nums[ind] - target);
    return nottaken || taken;
}
bool twoSum(vector<int> &nums)
{
    int total = 0;
    for (auto i : nums)
        total += i;
    cout << total;
    if (total % 2 == 1)
        return false;
    int k = total / 2;
    vector<int> prev(k + 1, false);
    prev[0] = true;
    for (int ind = 1; ind < nums.size(); ind++)
    {
        vector<int> cur(k + 1, false);
        cur[0] = true;
        for (int target = 1; target <= k; target++)
        {
            int nottaken = prev[target];
            int taken = false;
            if (nums[ind] <= target)
            {
                taken = prev[target - nums[ind]];
            }
            cur[target] = nottaken || taken;
        }
        prev = cur;
    }

    /* if(ispresent(nums.size()-1,nums,total/2)){
        return "True";
    }; */
    return prev[k];
}
int main()
{

    vector<int> nums = {5, 1, 11, 6};

    cout << "Output: " << twoSum(nums) << endl;

    return 0;
}