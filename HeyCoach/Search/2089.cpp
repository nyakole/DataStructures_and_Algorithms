// https://leetcode.com/problems/find-target-indices-after-sorting-numsay/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int searchRange(vector<int> &nums, int x)
{
    int low = 0;
    int high = nums.size();
    int firstindex = -1;
    int lastindex = -1;
    vector<int> ans;
    /* while (low <= high)
    {
        cout << low << " first" << endl;
        int mid = low + (high - low) / 2;
        cout << mid << " mid " << nums[mid] << endl;
        if (nums[mid] == x)
        {

            if (mid-1 > 0 &&nums[mid - 1] != x  )
            {
                firstindex = mid;
                low = mid + 1;
                cout << low << " low" << endl;
            }
            else if (nums[mid + 1] != x && mid <= nums.size() - 1)
            {

                lastindex = mid;
                high = mid - 1;
            }
        }
        else if (nums[mid] < x)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    } */
    int lowerbound = lower_bound(nums.begin(),nums.end(),x)-nums.begin();
    int upeerbound= upper_bound(nums.begin(),nums.end(),x)-nums.begin()-1;
    if(lowerbound<nums.size() && nums[lowerbound]==x){
        return upeerbound-lowerbound+1;
    }
    
    return 0;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";

    vector<int> nums{1, 1 ,1 ,2, 2, 3 ,3};
    /* cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    } */

    //vector<int> ans = searchRange(nums, 3);

    cout << "Output: " <<searchRange(nums, 6)<< endl;

    /* for (auto num : ans)
    {
        cout << num << " ";
    } */
    return 0;
}