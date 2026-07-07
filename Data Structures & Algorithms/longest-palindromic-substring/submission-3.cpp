class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=1;
        vector<vector<bool>> dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                dp[i-1][i]=true;
                maxlen=2;
                start=i-1;
            }
        }
        for(int len=3;len<=n;len++){
            for(int j=0;j+len-1<n;j++){
                int i=j+len-1;
                if(s[i]==s[j] && dp[j+1][i-1]){
                    dp[j][i]=true;
                    if(len>maxlen){
                        maxlen=len;
                        start=j;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
