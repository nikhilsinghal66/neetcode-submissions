class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        priority_queue<pair<int,int>> pq;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                pq.push({count, nums[i - 1]});
                count=1;
            } else {
                count++;
            }
        }
        vector<int> ans;
        pq.push({count, nums[n - 1]});
        while(k>0){
            int temp=pq.top().second;
            pq.pop();
            ans.push_back(temp);
            k--;
        }
        return ans;
    }
};
