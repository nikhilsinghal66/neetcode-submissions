class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        vector<int> temp=intervals[0];
        int count=0;
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(start<temp[1]){
                count++;
            }
            else{
                temp=intervals[i];
            }
        }
        return count;
    }
};
