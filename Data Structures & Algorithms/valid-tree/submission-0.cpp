class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &adjlist,int parent){
        vis[node]=1;
        for(auto it:adjlist[node]){
            if(!vis[it]){
                if(dfs(it,vis,adjlist,node)){
                    return true;
                }
            }
            else if(parent!=it){
                return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        if(edges.size()!=n-1){
            return false;
        }
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,adjlist,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};
