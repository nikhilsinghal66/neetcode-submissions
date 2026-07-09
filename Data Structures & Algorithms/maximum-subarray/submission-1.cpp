class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane algo...
        int n=nums.size();
        int ans=nums[0];
        int curr_element_sum=nums[0];
        for(int i=1;i<n;i++){
            int curr_element=nums[i];
            curr_element_sum=max(curr_element,curr_element_sum+nums[i]);
            ans=max(ans,curr_element_sum);
        }
        return ans;
    }
};
