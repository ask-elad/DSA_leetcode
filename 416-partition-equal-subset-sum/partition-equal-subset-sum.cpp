class Solution {
public:
    vector<vector<int>> dp;

    bool rec(vector<int>& nums, int ind, int target){
        if(target == 0) return true;
        if(ind < 0 || target < 0) return false;

        if(dp[ind][target] != -1)
            return dp[ind][target];

        bool take = rec(nums, ind - 1, target - nums[ind]);
        bool notT = rec(nums, ind - 1, target);

        return dp[ind][target] = take || notT;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;
        dp.resize(nums.size(), vector<int>(sum / 2 + 1, -1));

        return rec(nums, nums.size() - 1, sum / 2);
    }
};