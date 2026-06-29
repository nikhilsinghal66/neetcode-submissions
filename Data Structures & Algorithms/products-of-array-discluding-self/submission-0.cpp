class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product=1;
        int count_zero=0;
        for(auto x:nums){
            if(x==0){
                count_zero++;
            }
            else{
                product=product*x;
            }
        }
        int n=nums.size();
        vector<int> ans(n,0);
        if(count_zero>1){
            return ans;
        }
        else if(count_zero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=product;
                }
            }
            return ans;
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};
