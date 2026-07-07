class Solution {
public:
    int f(int ind,vector<int> &nums,vector<vector<int>> &dp,int n,int prev){
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        //Not_take...
        int left=0+f(ind+1,nums,dp,n,prev);
        int right=0;   
        if(prev==-1 || nums[ind]>nums[prev]){
            right=1 + f(ind+1,nums,dp,n,ind);
        }
        return dp[ind][prev+1]=max(left,right);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,nums,dp,n,prev);
    }
};
