// https://leetcode.com/problems/pancake-sorting/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pancakeSort(vector<int> &A)
{
    vector<int> res;
    int x, i;
    for (x = A.size(); x > 0; --x)
    {
        for (i = 0; A[i] != x; ++i)
            ;
        reverse(A.begin(), A.begin() + i + 1);
        res.push_back(i + 1);
        reverse(A.begin(), A.begin() + x);
        res.push_back(x);
    }
    return res;
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

    vector<int> ans = pancakeSort(nums);

    cout << "Output: " << endl;

    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}