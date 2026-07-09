class Solution {
public:
    int f(int i,int j,vector<vector<int>> &dp,string &s,string &p){
        if (j == p.size())
            return i == s.size();
        if(dp[i][j]!=-1) return dp[i][j];
        bool check=false;
        if(j+1<p.size() && p[j+1]=='*'){
            check|=f(i,j+2,dp,s,p);
            if(i<s.size() && (s[i]==p[j] || p[j]=='.') ){
                check|=f(i+1,j,dp,s,p);
            }
        }

            if(i<s.size() && (s[i]==p[j] || p[j]=='.')){
                check|=f(i+1,j+1,dp,s,p);
            }
        return dp[i][j]=check;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,dp,s,p);
    }
};
