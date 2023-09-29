// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int binaryS(vector<int> &v, int sz)
{
    int l = 0, r = sz, mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] < 0)
            r = mid;
        else
            l = mid + 1;
    }
    return r; // Returns the index
    // The binaryS function is used to find the index where
    // negative numbers start in a sorted vector.
    // It performs a binary search to locate the first
    // occurrence of a negative number.
    //////////////////////////////////////
    // C++ STL upper_bound
    //  return upper_bound(v.begin(),v.end(),0,greater<int>())
    //    -v.begin();
}
int countNegatives(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int sum = 0;

    // Using binaryS to find the number i_max
    vector<int> col0(n);
    for (int i = 0; i < n; i++)
        col0[i] = grid[i][0];
    int i_max = binaryS(col0, n);
    // The binaryS function is called to find the number of
    // negative numbers in the first column of the grid.
    // It returns the index where the negative numbers start,
    // which represents the number of negative numbers in
    // that column.

    for (int i = 0; i < i_max; i++)
    {
        sum += m - binaryS(grid[i], m);
    }
    // Iterate through the rows up to i_max.
    // For each row, binaryS is called to find the number of
    // negative numbers in that row.
    // Subtracting this count from m gives the number of
    // non-negative numbers in the row.
    // The result is added to the sum.

    sum += (n - i_max) * m;
    // Add the number of non-negative numbers in the remaining
    // rows (n-i_max) to the sum.
    // Since all elements in these rows are non-negative, the
    // count is simply m (the number of columns).

    return sum; // Return the total count of negative numbers
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

    cout << "Output: " << search(nums, 2) << endl;

    return 0;
}