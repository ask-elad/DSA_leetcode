class Solution {
public:
    int rec(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        if(m == 0 && n == 0){
            return grid[m][n];
        }
        if(m < 0 || n < 0) return 1e9;
        if(dp[m][n] != INT_MIN)return dp[m][n];

        int up = rec(grid, m-1, n, dp);
        int left=rec(grid, m, n-1, dp);

        return dp[m][n] = grid[m][n] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, INT_MIN));

        return rec(grid, m-1, n-1, dp);
    }
};