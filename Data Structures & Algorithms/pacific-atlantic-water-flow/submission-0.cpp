class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& heights,vector<vector<int>> &vis){
        vis[row][col]=1;
        int n=heights.size();
        int m=heights[0].size();
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
            && heights[nrow][ncol]>=heights[row][col]){
                dfs(nrow,ncol,heights,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> pacific(n,vector<int>(m,0));
        //Top view...
        for(int i=0;i<m;i++){
            dfs(0,i,heights,pacific);
            dfs(n-1,i,heights,atlantic);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pacific);
            dfs(i,m-1,heights,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
