class Solution {
public:
    int rec(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int take = 0;
        int notT = 0;

        notT = rec(nums, ind + 1, prev, dp);
        if(prev == -1 || nums[prev] < nums[ind])
            take = 1 + rec(nums, ind + 1, ind, dp);

        return dp[ind][prev + 1] = max(take, notT);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return rec(nums, 0, -1, dp);
    }
};