class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1);
        for(auto it:times){
            int a=it[0];
            int b=it[1];
            int time=it[2];
            adjlist[a].push_back({b,time});
        }
        //Shortest Distance Concepts...
        // queue<pair<int,int>> q;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!q.empty()){
            auto temp=q.top();
            int time=temp.first;
            int node=temp.second;
            q.pop();
            for(auto it:adjlist[node]){
                if(time+it.second<dist[it.first]){
                    dist[it.first]=time+it.second;
                    q.push({dist[it.first],it.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            else{
                ans=max(ans,dist[i]);
            }
        }
        return ans;
    }
};
