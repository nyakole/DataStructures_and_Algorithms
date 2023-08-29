// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
vector<int> sortedSquares(vector<int> &nums)
{

    int n = nums.size();
    vector<int> result(n);
    int left = 0;
    int right = n - 1;
    int index = n - 1;
    while (left <= right)
    {
        int leftsquare = nums[left] * nums[left];
        int rightsquare = nums[right] * nums[right];
        if (leftsquare > rightsquare)
        {
            result[index--] = leftsquare;
            left++;
        }
        else
        {
            result[index--] = rightsquare;
            right--;
        }
    }
    return result;
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

    vector<int> result = sortedSquares(nums);
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}