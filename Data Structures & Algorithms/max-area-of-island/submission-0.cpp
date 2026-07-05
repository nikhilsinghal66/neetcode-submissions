class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int row,int col
    ,int &count){
        // queue<pair<int,pair<int,int>>> q;
        // q.push({1,{row,col}});
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        count++;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 &&
            !vis[nrow][ncol]){
                dfs(grid,vis,nrow,ncol,count);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int count=0;
                    dfs(grid,vis,i,j,count);
                    max_area=max(max_area,count);
                }
            }
        }
        return max_area;
    }
};
