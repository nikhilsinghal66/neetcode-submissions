class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set1;
        if(nums.empty()) return 0;
        for (auto x : nums) {
            set1.insert(x);
        }
        int n = nums.size();
        int ans=INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            // if(!set1.count(nums[i])) continue;
            while (set1.count(temp - 1)) {
                temp = temp - 1;
            }
            int count=1;
            set1.erase(temp);
            while(set1.count(temp+1)){
                count++;
                temp++;
                set1.erase(temp);
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
