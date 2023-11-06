// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& Arr, int n, int k) {
    // Create two arrays, 'ahead' and 'cur', to track the maximum profit at each step
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap],
                                       -Arr[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                       Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the 'ahead' array with the current values
        ahead = cur;
    }

    return ahead[0][k];
}

int main() {
    vector<int> prices = {1,2};
    int n = prices.size();
    int k = 1;

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n, k) << endl;
    return 0;
}
