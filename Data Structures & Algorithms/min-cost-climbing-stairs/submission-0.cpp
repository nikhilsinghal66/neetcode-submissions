class Solution {
public:
    int f(int ind,vector<int> &dp,vector<int> &cost){
        if(ind<=1){
            return cost[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        //+1 jump...
        int left=cost[ind]+f(ind-1,dp,cost);
        //+2 jump...
        int right=0;
        if(ind>1){
            right=cost[ind]+f(ind-2,dp,cost);
        }
        return dp[ind]=min(left,right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(f(n-1,dp,cost),f(n-2,dp,cost));
    }
};
