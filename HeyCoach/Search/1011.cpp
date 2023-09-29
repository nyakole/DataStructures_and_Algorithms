// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int daysCalculate(vector<int> &weights, int capacity, int n)
{
    int sum = 0;
    int days = 1;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];

        if (sum > capacity)
        {

            sum = weights[i];
            days++;
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    int n = weights.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int dayscal = daysCalculate(weights, mid, n);
        /* if(dayscal==days){
            return mid;
        } */
        if (dayscal <= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int n;
    int days;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "Enter the number of days: ";
    cin >> days;
    cout << "Output: " << shipWithinDays(nums, days) << endl;

    return 0;
}