class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        int buyP = 0;
        int sellP =0;

        int n = prices.size();

        if(prices.size() == 0)return 0;
        if(prices.size() == 1)return 0;
        if(prices.size() == 2 && prices[0] >= prices[1])return 0;
        if(prices.size() == 2 && prices[0] < prices[1])return prices[1] - prices[0];

        for(int i =1; i<n; i++){
            if(prices[i] >= prices[i-1]){
                sellP = i;
            }
            else{
                prof = prof + prices[sellP] - prices[buyP];
                buyP = i;
                sellP = i;
            }
        }

        prof = prof + prices[sellP] - prices[buyP];
        return prof;
    }
};