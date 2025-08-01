class Solution {
public:

    bool isValid(vector<int> nums, int k, int maxAllowedSum) {
        int count = 1, currSum = 0;
        for (int num : nums) {
            if (currSum + num > maxAllowedSum) {
                count++;
                currSum = num;
            } else {
                currSum += num;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixSum(n); 

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1]; 
        }

        int low = *max_element(nums.begin(), nums.end());
        int high = prefixSum[n - 1];

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (isValid(nums, k, mid)) { 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
