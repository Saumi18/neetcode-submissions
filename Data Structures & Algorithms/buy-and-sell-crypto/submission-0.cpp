class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l=0, r=1;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                max_profit = max(profit,max_profit);
            }
            else l = r;
            r++;
        }
        return max_profit;
    }
};
