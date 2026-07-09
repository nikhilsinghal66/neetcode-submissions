class Solution {
public:
    int f(int row,int col,vector<vector<int>> &dp,vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        if(row<0 || col<0 || row>=n || col>=m){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int count4=1;
        int count1=1;
        int count2=1;
        int count3=1;
        if(row<n-1 && matrix[row+1][col]>matrix[row][col]){
            count1=1+f(row+1,col,dp,matrix);
        }
        if(row>0 && matrix[row-1][col]>matrix[row][col]){
            count2=1+f(row-1,col,dp,matrix);
        }
        if(col>0 && matrix[row][col-1]>matrix[row][col]){
            count3=1+f(row,col-1,dp,matrix);
        }
        if(col<m-1 && matrix[row][col+1]>matrix[row][col]){
            count4=1+f(row,col+1,dp,matrix);
        }
        return dp[row][col]=max({count4,count1,count2,count3});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(i,j,dp,matrix));
            }
        }
        return ans;
    }
};
