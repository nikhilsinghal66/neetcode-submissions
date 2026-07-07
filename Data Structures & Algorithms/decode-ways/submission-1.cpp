class Solution {
public:
    int f(int ind,int n,vector<int> &dp,string s){
        if(ind==n){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        //take 1 ...
        int take1=f(ind+1,n,dp,s);
        //take 2...
        int take2=0;
        if(n-ind>1){
            int num=stoi(s.substr(ind,2));
            if(num>=10 && num<=26){
                take2=f(ind+2,n,dp,s);
            }
        }
        return dp[ind]=take1+take2;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,n,dp,s);
    }
};
