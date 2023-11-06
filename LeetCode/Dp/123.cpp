//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& Arr, int n) {
    // Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
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
        // Update the ahead state with the current state for the next iteration.
        ahead = cur;
    }

    return ahead[0][2];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Call the maxProfit function and print the result
    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}
