class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        int minBuy = prices[0];
        int maxProfit = 0;
        for(int sell=0;sell<n;sell++){
            int profit = prices[sell] - minBuy;
            minBuy = min(minBuy,prices[sell]);
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};
