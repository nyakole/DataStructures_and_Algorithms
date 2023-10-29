// https://leetcode.com/problems/contains-duplicate-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
          unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
int main()
{
    int n,k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "Enter the k elements: ";
    cin>> k;

    cout << "Output: " << containsNearbyDuplicate(nums,k) << endl;

    return 0;
}