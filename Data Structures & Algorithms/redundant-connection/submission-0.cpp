class DSU{
public:
    vector<int> parents;
    vector<int> rank;
    DSU(int n){
        parents.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parents[i]=i;
        }
    }
    int findUparent(int node){
        if(node==parents[node]){
            return node;
        }
        return parents[node]=findUparent(parents[node]);
    }
    void RankUnion(int node1,int node2){
        int fUpar1=findUparent(node1);
        int fUpar2=findUparent(node2);
        if(fUpar1==fUpar2){
            return;
        }
        if(rank[fUpar1]<rank[fUpar2]){
            parents[fUpar1]=fUpar2;
        }
        else if(rank[fUpar2]<rank[fUpar1]){
            parents[fUpar2]=fUpar1;
        }
        else{
            parents[fUpar2]=fUpar1;
            rank[fUpar1]++;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            if(dsu.findUparent(a)==dsu.findUparent(b)){
                return it;
            }
            dsu.RankUnion(a,b);
        }
        return {};
    }
};
