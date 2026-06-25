class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n + 3, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int turn = 0; turn < 2; turn++){    
                int sum = 0;

                if(turn){
                    int case1 = stones[ind] + dp[ind + 1][0];
                    int case2 = INT_MIN;
                    int case3 = INT_MIN;

                    if(ind + 1 < n)
                        case2 = stones[ind] + stones[ind + 1] + dp[ind + 2][0];

                    if(ind + 2 < n)
                        case3 = stones[ind] + stones[ind + 1] + stones[ind + 2] + dp[ind + 3][0];

                    sum = max({case1, case2, case3});
                }
                else{
                    int case1 = -stones[ind] + dp[ind + 1][1];
                    int case2 = INT_MAX;
                    int case3 = INT_MAX;

                    if(ind + 1 < n)
                        case2 = -stones[ind] - stones[ind + 1] + dp[ind + 2][1];

                    if(ind + 2 < n)
                        case3 = -stones[ind] - stones[ind + 1] - stones[ind + 2] + dp[ind + 3][1];

                    sum = min({case1, case2, case3});
                }

                dp[ind][turn] = sum;
            }
        }

        int ans = dp[0][1];

        if(ans == 0) return "Tie";
        if(ans > 0) return "Alice";
        return "Bob";
    }
};