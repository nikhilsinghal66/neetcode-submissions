class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int count=0;
        for(int i=0;i<n;i++){
            int a1=intervals[i][0];
            int a2=intervals[i][1];
            if(a2<newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else{
                temp=newInterval;
                break;
            }
            count++;
        }
        if(temp.empty()){
            temp=newInterval;
        }
        for(int i=count;i<n;i++){
            int a1=intervals[i][0];
            int a2=intervals[i][1];
            if(a1<=temp[1]){
                int val1=min(a1,temp[0]);
                int val2=max(a2,temp[1]);
                temp[0]=val1;
                temp[1]=val2;
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
