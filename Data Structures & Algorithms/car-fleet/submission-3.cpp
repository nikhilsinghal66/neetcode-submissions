class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> time;
        for(int i=0;i<n;i++){
            time.push_back({position[i],speed[i]});
        }
        sort(time.begin(),time.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.first>b.first;
        });
        stack<double> st;
        for(int i=0;i<n;i++){
            double time1=(double)(target-time[i].first)/time[i].second;
            if(st.empty()){
                st.push(time1);
            }
            if(!st.empty() && st.top()<time1){
                st.push(time1);
            }

        }
        return st.size();
    }
};
