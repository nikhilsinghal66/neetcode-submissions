class Solution {
public:
    int f(int s1,int s2,string text1,string text2,vector<vector<int>> &dp){
        if(s1<0 || s2<0){
            return 0;
        }
        if(dp[s1][s2]!=-1) return dp[s1][s2];
        int count=0;
        int count1=0;
        if(text1[s1]==text2[s2]){
            count=1+f(s1-1,s2-1,text1,text2,dp);
        }
        else{
            count1=max(f(s1-1,s2,text1,text2,dp),f(s1,s2-1,text1,text2,dp));
        }
        return dp[s1][s2]=max(count,count1);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};
