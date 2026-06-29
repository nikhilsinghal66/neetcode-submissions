class Solution {
public:
    bool f(int ind,string s){
        string temp="987";
        for(int i=0;i<3;i++){
            if(s[ind++]!=temp[i]){
                return false;
            }
        }
        return true;
    }

    string encode(vector<string>& strs) {
        string temp="";
        for(auto x:strs){
            temp+=x;
            temp+="987";
        }
        return temp;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='9' && f(i,s)==true){
                ans.push_back(temp);
                temp="";
                i+=2;
            }
            else{
                temp+=s[i];
            }
        }
        return ans;
    }
};
