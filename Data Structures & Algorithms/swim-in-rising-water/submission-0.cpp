class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        vector<int> delrow={-1,0,1,0};
        vector<int> delcol={0,1,0,-1};
        while(!pq.empty()){
            auto temp=pq.top();
            int level=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            pq.pop();
            if(row==n-1 && col==m-1){
                return level;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int numMax=max(level,grid[nrow][ncol]);
                    if(numMax<dist[nrow][ncol]){
                        pq.push({numMax,{nrow,ncol}});
                        dist[nrow][ncol]=numMax;
                    }
                }
            }
        }
        return -1;
    }
};
