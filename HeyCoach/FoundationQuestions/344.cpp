// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void reverseString(vector<char> &s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left <= right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<char> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    reverseString(nums);

    cout << "Output: " << endl;

    for (auto num : nums)
    {
        cout << num << " ";
    }
    return 0;
}