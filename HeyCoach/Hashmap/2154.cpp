// https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/
 int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(auto i : nums) {
            if(original == i) original *= 2;
        }
        return original;
    }