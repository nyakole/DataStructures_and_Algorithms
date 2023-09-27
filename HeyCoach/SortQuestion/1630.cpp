// https://leetcode.com/problems/arithmetic-subarrays/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    vector<bool> ans;
    for (int i = 0; i < l.size(); i++)
    {
        vector<int> tmp;
        for (int k = l[i]; k < r[i] + 1; k++)
        {
            cout << "k value " << k;
            tmp.push_back(nums[k]);
        };
        cout << endl;
        cout << nums.size() << " " << tmp.size() << " l size " << l[i] << " r size " << r[i] << endl;
        sort(tmp.begin(), tmp.end());
        int sub = abs(tmp[1]) - abs(tmp[0]);
        bool flag = true;
        for (int j = 0; j < tmp.size() - 1; j++)
        {
            cout << tmp[j];
            if (abs(tmp[j + 1]) - abs(tmp[j]) != sub)
            {
                flag = false;
                break;
            }
        }
        cout << endl;
        ans.push_back(flag);
    }
    return ans;
}
int main()
{
    vector<int> nums{4, 6, 5, 9, 3, 7};
    vector<int> l{0, 0, 2};
    vector<int> r{2, 3, 5};
    vector<bool> ans = checkArithmeticSubarrays(nums, l, r);

    cout << "Output: " << endl;

    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}