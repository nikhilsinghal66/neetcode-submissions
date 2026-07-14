class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<=temp[1]){
                temp[0]=min(intervals[i][0],temp[0]);
                temp[1]=max(intervals[i][1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
