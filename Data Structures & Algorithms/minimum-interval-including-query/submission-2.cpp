class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size();
        int m=queries.size();
        vector<long long> arr(10000+1,INT_MAX);
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            for(int j=start;j<=end;j++){
                if(arr[j]>end-start+1){
                    arr[j]=end-start+1;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            if(arr[queries[i]]!=INT_MAX){
                ans.push_back(arr[queries[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
