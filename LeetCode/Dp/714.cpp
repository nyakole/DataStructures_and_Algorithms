//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/


#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int n, int fee, vector<int>& Arr) {
    if (n == 0) return 0; // Edge case: No stocks to trade.

    vector<long> ahead(2, 0); // To track maximum profit one step ahead
    vector<long> cur(2, 0);   // To track current maximum profit

    // Initialize both ahead[0] and ahead[1] to 0 as the base condition
    ahead[0] = ahead[1] = 0;

    long profit;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] - fee + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur;
    }
    return cur[0]; // Return the maximum profit for buying.
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}
