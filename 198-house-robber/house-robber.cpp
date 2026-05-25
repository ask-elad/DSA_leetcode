class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2){
            if(nums.size() == 0) return 0;
            if(nums.size() == 1) return nums[0];
            if(nums.size() == 2) return (nums[1] > nums[0] ? nums[1] : nums[0]);
        }

        int prev_2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            int curr = max(prev, prev_2 + nums[i]);

            prev_2 = prev;
            prev = curr;
        }

        return prev;
    }
};