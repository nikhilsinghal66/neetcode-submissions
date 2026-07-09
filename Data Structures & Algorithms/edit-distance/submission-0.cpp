class Solution {
public:
    int f(int i,int j,int n1,int n2,vector<vector<int>> &dp,string &word1,string &word2){
        if(j>=n2){
            return n1-i;
        }
        if(i>=n1){
            return n2-j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        //If similar...
        int count1=1e9;
        int count2=1e9;
        if(word1[i]==word2[j]){
            count1=f(i+1,j+1,n1,n2,dp,word1,word2);
        }
        else{
            //replace
            int count3=1+f(i+1,j+1,n1,n2,dp,word1,word2);
            //remove
            int count4=1+f(i+1,j,n1,n2,dp,word1,word2);
            //insert
            int count5=1+f(i,j+1,n1,n2,dp,word1,word2);
            count2=min({count5,count3,count4});
        }
        return dp[i][j]=min(count1,count2);
    }

    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(0,0,n1,n2,dp,word1,word2);
    }
};
