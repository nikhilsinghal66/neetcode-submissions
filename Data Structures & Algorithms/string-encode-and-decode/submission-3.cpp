class Solution {
public:

    string encode(vector<string>& strs) {
        string temp="";
        int n=strs.size();
        for(int i=0;i<n;i++){
            int sze=strs[i].size();
            temp+=to_string(sze)+'#'+strs[i];
        }
        return temp;
    }

    vector<string> decode(string s) {
        int n=s.size();
        int i=0;
        vector<string> ans;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            string temp=s.substr(j+1,len);
            ans.push_back(temp);
            i=j+1+len;
        }
        return ans;
    }
};
