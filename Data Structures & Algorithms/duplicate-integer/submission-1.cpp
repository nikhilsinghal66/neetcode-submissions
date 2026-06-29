class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set1;
        for(auto x:nums){
            set1.insert(x);
        }
        int n=nums.size();
        if(set1.size()!=n){
            return true;
        }
        return false;
        
    }
};