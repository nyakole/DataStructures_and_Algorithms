// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *Arr, int n) {
    // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

    // Base condition: When there are no stocks left, the profit is 0.
    ahead[0] = ahead[1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

    // The maximum profit is stored in cur[0] after all calculations
    return cur[0];
}

int main() {
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}

