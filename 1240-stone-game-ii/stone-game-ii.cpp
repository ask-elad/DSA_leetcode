class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int m = n; m >= 1; m--){
                for(int turn = 0; turn < 2; turn++){

                    int result = (turn == 1) ? INT_MIN : INT_MAX;
                    int stones = 0;
                    for(int x = 1; x <= min(2 * m, n - ind); x++){

                        stones += piles[ind + x - 1];
                        if(turn){
                            result = max(result, stones + dp[ind + x][max(m, x)][0]);

                        }else{
                            result = min(result, dp[ind + x][max(m, x)][1]);
                        }
                    }
                    dp[ind][m][turn] = result;
                }
            }
        }
        return dp[0][1][1];
    }
};