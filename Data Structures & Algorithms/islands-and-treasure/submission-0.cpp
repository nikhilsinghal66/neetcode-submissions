class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //Multiverse BFS...
        int n=grid.size();
        int INF=pow(2,31)-1;
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        // vector<vector<int>> ans=grid;
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int dist=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            if(grid[row][col]==INF){
                grid[row][col]=dist;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==INF 
                && !vis[nrow][ncol]){
                    q.push({dist+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
};
