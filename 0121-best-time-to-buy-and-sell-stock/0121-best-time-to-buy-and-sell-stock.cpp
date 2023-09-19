class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minElementTillNow = prices[0];
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            minElementTillNow = min(minElementTillNow, prices[i]);
            int profit = prices[i] - minElementTillNow;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};