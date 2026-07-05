class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int minutes=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            ans=max(ans,minutes);
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
                grid[nrow][ncol]==1){
                    q.push({minutes+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return ans;
    }
};
