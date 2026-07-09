class Solution {
public:
    int f(int i,int j,int n1,int m1,string s1,string s2,string s3,vector<vector<int>> &dp){
        if(i==n1 && j==m1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int check=0;
        int check1=0;
        if(i<n1 && s3[i+j]==s1[i]){
            check=f(i+1,j,n1,m1,s1,s2,s3,dp);
        }
        if(j<m1 && s3[i+j]==s2[j]){
            check1=f(i,j+1,n1,m1,s1,s2,s3,dp);
        }
        return dp[i][j]=check|| check1;

    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int m1=s2.size();
        if(n1+m1!=s3.size()) return false;
        vector<vector<int>> dp(n1+1,vector<int>(m1+1,-1));
        return f(0,0,n1,m1,s1,s2,s3,dp);
    }
};
