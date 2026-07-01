class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<points.size();i++){
            int ans=0;
            ans=(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            pq.push({ans,points[i][0],points[i][1]});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            auto temp=pq.top();
            pq.pop();
            ans.push_back({temp[1],temp[2]});
        }
        return ans;
    }
};
