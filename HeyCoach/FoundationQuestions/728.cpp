// https://leetcode.com/problems/self-dividing-numbers/
#include <iostream>
#include <vector>
using namespace std;
vector<int> selfDividingNumbers(int left, int right)
{
    int found, iAux, d;
    vector<int> nums;
    for (int i = left; i <= right; i++)
    {
        for (found = 0, iAux = i; iAux != 0; iAux /= 10)
        {
            d = iAux % 10;
            if (d == 0 || i % d != 0)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            nums.emplace_back(i);
        }
    }
    return nums;
}
int main()
{
    int left;
    int right;
    cin >> left >> right;

    vector<int> nums = selfDividingNumbers(left, right);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}