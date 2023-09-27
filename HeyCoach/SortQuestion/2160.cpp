// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimumSum(int num)
{
    vector<int> a;
    int tmp = num;
    while (tmp > 0)
    {
        int rem = tmp % 10;
        a.push_back(rem);
        tmp /= 10;
    }
    sort(a.begin(), a.end());
    return a[0] * 10 + a[2] + a[1] * 10 + a[3];
}
int main()
{
    int num;
    cin >> num;
    cout << minimumSum(num);
    return 0;
}