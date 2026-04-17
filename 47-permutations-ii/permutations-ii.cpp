class Solution {
public:
    void permut(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<int>& vis, int n){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == 1) continue;
            if(i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0) continue;

            vis[i] = 1;
            ds.push_back(nums[i]);

            permut(nums, ds, ans, vis, n);

            ds.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;

        int n = nums.size();
        vector<int> vis(n, 0);

        sort(nums.begin(), nums.end());

        permut(nums, ds, ans, vis, n);
        return ans;
    }
};