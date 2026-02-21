class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0)return 0;
        if(nums.size() == 1 && nums[0] < target)return 0;
        if(nums.size() == 1 && nums[0] >= target)return 1;

        int l =0;
        int r = 0;

        int tot= 0;
        int minn = INT_MAX;

        while(r < n){

            tot = tot + nums[r];

            while(tot >= target){
                minn = min(minn, r-l+1); 
                tot = tot - nums[l];
                l++;
            }
            r++;
        }

        if(minn == INT_MAX) return 0;
        return minn;
    }
};