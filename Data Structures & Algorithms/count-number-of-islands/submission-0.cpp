class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        vector<int> delrow={0,1,0,-1};
        vector<int> delcol={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
                && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count_numIslands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,grid,vis);
                    count_numIslands++;
                }
            }
        }
        return count_numIslands;
    }
};
