class KthLargest {
public:
    priority_queue<int> pq;
    int top_k=0;
    KthLargest(int k, vector<int>& nums) {
        top_k=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> ans;
        for(int i=0;i<top_k;i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        int result=ans[ans.size()-1];
        for(int i=0;i<ans.size();i++){
            pq.push(ans[i]);
        }
        return result;
    }
};
