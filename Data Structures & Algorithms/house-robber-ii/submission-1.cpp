class Solution {
public:
    int f1(int ind,vector<int> &dp,vector<int> &nums){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        //NotTake...
        int notTake=0+f1(ind-1,dp,nums);
        //Take it...
        int take=0;
        if(ind>=1){
            take=nums[ind]+f1(ind-2,dp,nums);
        }
        return dp[ind]=max(notTake,take);
    }

    int f(int ind,vector<int> &dp,vector<int> &nums){
        if(ind==1){
            return nums[ind];
        }
        if(ind<=0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        //NotTake...
        int notTake=0+f(ind-1,dp,nums);
        //Take it...
        int take=0;
        if(ind>=1){
            take=nums[ind]+f(ind-2,dp,nums);
        }
        return dp[ind]=max(notTake,take);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp1(n,-1);
        return max(f(n-1,dp,nums),f1(n-2,dp1,nums));
    }
};
