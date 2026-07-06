class Solution {
public:
    int maxAmount(int ind,vector<int> &dp,vector<int> &nums){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        //Skip it...
        int skip_step=0 + maxAmount(ind-1,dp,nums);
        //Take it...
        int right=0;
        if(ind>=1){
            right=nums[ind]+maxAmount(ind-2,dp,nums);
        }
        return dp[ind]=max(skip_step,right);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return maxAmount(n-1,dp,nums);
    }
};











