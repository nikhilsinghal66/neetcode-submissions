class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int count=nums[0];
        for(int i=1;i<n;i++){
            if(count<i){
                return false;
            }
            else{
                count=max(nums[i]+i,count);
            }
        }
        return true;
    }
};
