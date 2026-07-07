class Solution {
public:
    int f(int ind,int amount,vector<vector<int>> &dp,vector<int> &coins){
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else{
                return 1e9;
            }
        }
        //CHECK IN DP...
        if(dp[ind][amount]!=-1) return dp[ind][amount];

        //NOT_TAKE...
        int left= 0 + f(ind-1,amount,dp,coins);

        //TAKE_IT...
        int right=1e9;
        if(amount>=coins[ind]){
            right=1 + f(ind,amount-coins[ind],dp,coins);
        }
        return dp[ind][amount]=min(left,right);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,dp,coins);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};
