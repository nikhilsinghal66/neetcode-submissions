class Solution {
public:
    bool f(int amount,vector<int> &nums,int ind,vector<vector<int>> &dp){
        if(ind==0){
            return amount==nums[ind];
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        //Not_take ...
        int left=f(amount,nums,ind-1,dp);
        int right=0;
        if(amount>=nums[ind]){
            right=f(amount-nums[ind],nums,ind-1,dp);
        }
        return dp[ind][amount]=left || right;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return f(sum/2,nums,n-1,dp);
    }
};
