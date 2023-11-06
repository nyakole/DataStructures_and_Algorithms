// https://leetcode.com/problems/house-robber-ii/description/
class Solution {
public:
   int solve(vector<int>& arr) {
       int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    
    for (int i = 1; i < arr.size(); i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    
    return prev;  // Return the maximum sum
    }
    int rob(vector<int>& arr) {
         vector<int> arr1;
    vector<int> arr2;
    
    if(arr.size()==1)
       return arr[0];
    
    for(int i=0; i<arr.size(); i++){
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=arr.size()-1) arr2.push_back(arr[i]);
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
    }
};