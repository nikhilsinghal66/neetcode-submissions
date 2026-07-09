class Solution {
public:
    int f(vector<int>&prices,vector<vector<int>> &dp,int n,int ind,int buy){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ibuy=0;
        int notbuy=0;
        int notbuy1=0;
        int ibuy1=0;
        if(buy){
            ibuy=-prices[ind] + f(prices,dp,n,ind+1,!buy);
            ibuy1=f(prices,dp,n,ind+1,buy);
        }
        else{
            notbuy1=f(prices,dp,n,ind+1,buy);
            notbuy=prices[ind]+f(prices,dp,n,ind+2,!buy);
        }
        return dp[ind][buy]=max({ibuy,ibuy1,notbuy1,notbuy});
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,dp,n,0,1);
    }
};
