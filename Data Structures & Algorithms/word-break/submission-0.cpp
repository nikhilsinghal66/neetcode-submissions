class Solution {
public:
    int f(int ind,vector<int> &dp,vector<string>& wordDict,string &s){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1) return dp[ind];
        for(auto word:wordDict){
            int len=word.size();
            if(ind+len<=s.size() && s.substr(ind,len)==word){
                if(f(ind+len,dp,wordDict,s)){
                    return dp[ind]=1;
                }
            }
        }
        return dp[ind]=0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,dp,wordDict,s);
    }
};
