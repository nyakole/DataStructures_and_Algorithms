// https://leetcode.com/problems/combination-sum-iv/description/

#include <bits/stdc++.h>
using namespace std;



int combinationSum4(vector<int>& num, int k) {
    int n = num.size();
    vector<unsigned long long> prev(k + 1, 0);
    prev[0] = 1;
        for (int target = 1; target <= k; target++) {
            for (int ind = 0; ind < n; ind++) {
            if (target - num[ind] >=0) {
                prev[target]+= prev[target - num[ind]];
            } 
        }       
    }
    return prev[k];
    }

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int target = 4;

    cout << "The number of subsets found is " << combinationSum4(  arr,target) << endl;

    return 0;  // Return 0 to indicate successful program execution
}
