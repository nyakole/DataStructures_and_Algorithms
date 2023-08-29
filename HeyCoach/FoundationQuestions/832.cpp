// https://leetcode.com/problems/flipping-an-image/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{

    int n = image.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n + 1) / 2; j++)
        {
            int temp = image[i][j] ^ 1;
            image[i][j] = image[i][n - 1 - j] ^ 1;
            image[i][n - 1 - j] = temp;
        }
    }
    return image;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<vector<int>> nums;
    vector<int> temp(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp[j];
        }
        nums.push_back(temp);
    }
    vector<vector<int>> result = flipAndInvertImage(nums);
    for (auto num1 : nums)
    {
        for (auto num : num1)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}