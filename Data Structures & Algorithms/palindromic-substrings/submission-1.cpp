class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            count++;
            dp[i][i]=true;
        }
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                count++;
                dp[i-1][i]=true;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=len+i-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    count++;
                    dp[i][j]=true;
                }
            }
        }
        return count;
    }
};
