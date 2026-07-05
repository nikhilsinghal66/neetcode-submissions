class Solution {
public:
    void dfs(int node,vector<int> &vis , vector<vector<int>> &adjlist){
        vis[node]=1;
        for(auto it:adjlist[node]){
            if(!vis[it]){
                dfs(it,vis,adjlist);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        //Adjacency list ...
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adjlist);
            }
        }
        return ans;
    }
};
