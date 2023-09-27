// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxCoins(vector<int> &A)
{
    sort(A.begin(), A.end());
    int res = 0, n = A.size();
    for (int i = n / 3; i < n; i += 2)
        res += A[i];
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

    cout << "Output: " << maxCoins(nums) << endl;

    return 0;
}