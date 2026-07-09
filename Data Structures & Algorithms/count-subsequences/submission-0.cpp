class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int count1=0;
        int count2=0;
        int count3=0;
        if(s[i]==t[j]){
            count1=f(i-1,j-1,s,t,dp);
            count3=f(i-1,j,s,t,dp);
        }
        if(s[i]!=t[j]){
            count2=f(i-1,j,s,t,dp);
        }
        return dp[i][j]=count1+count2+count3;
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};
