class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }

    bool UnionRank(int node1,int node2){
        int Upar1=findUpar(node1);
        int Upar2=findUpar(node2);
        if(Upar1==Upar2){
            return false;
        }
        if(rank[Upar1]<rank[Upar2]){
            parent[Upar1]=parent[Upar2];
        }
        else if(rank[Upar1]>rank[Upar2]){
            parent[Upar2]=parent[Upar1];
        }
        else{
            parent[Upar2]=parent[Upar1];
            rank[Upar1]++;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int cost=abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end(),[](vector<int> &a ,vector<int> &b){
            return a[0]<b[0];
        });
        DSU dsu(points.size()+1);
        int ans=0;
        for(auto it:edges){
            int a=it[1];
            int b=it[2];
            int cost=it[0];
            if(dsu.UnionRank(a,b)){
                ans+=cost;
            }
        }
        return ans;
    }
};
