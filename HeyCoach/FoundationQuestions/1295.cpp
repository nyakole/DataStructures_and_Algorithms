// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

#include <iostream>
#include <vector>
using namespace std;
int findNumbers(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (to_string(nums[i]).length() % 2 == 0)
        {
            count++;
        }
    }
    return count;
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

    int result = findNumbers(nums);
    cout << "Output: " << result << endl;
    return 0;
}