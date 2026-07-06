class Solution {
public:
    void dfs(string str,vector<string> &ans,unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &mpp){
        while(!mpp[str].empty()){
            auto temp=mpp[str].top();
            mpp[str].pop();
            dfs(temp,ans,mpp);
        }
        ans.push_back(str);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mpp;
        vector<string> ans;
        for(auto it:tickets){
            string a=it[0];
            string b=it[1];
            mpp[a].push(b);
        }
        dfs("JFK",ans,mpp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
