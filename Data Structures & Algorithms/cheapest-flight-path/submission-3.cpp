class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjlist(n);
        for(auto it:flights){
            int a=it[0];
            int b=it[1];
            int price=it[2];
            adjlist[a].push_back({b,price});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto temp=q.front();
            int total_sum=temp.first;
            int node=temp.second.first;
            int price=temp.second.second;
            q.pop();
            if(total_sum==k+1){
                continue;
            }
            for(auto it:adjlist[node]){
                if(dist[node]!=INT_MAX && price+it.second<dist[it.first]){
                    dist[it.first]=price+it.second;
                    q.push({total_sum+1,{it.first,dist[it.first]}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
