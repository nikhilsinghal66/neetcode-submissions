class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy_stock=prices[0];
        int max_profit=0;
        for(int i=1;i<n;i++){
            max_profit=max(max_profit,prices[i]-buy_stock);
            buy_stock=min(buy_stock,prices[i]);
        }
        return max_profit; 
    }
};
