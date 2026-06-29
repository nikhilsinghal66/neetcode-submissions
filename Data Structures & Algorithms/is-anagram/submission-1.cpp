class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int m=t.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(mpp.find(t[i])!=mpp.end()){
                mpp[t[i]]--;
                if(mpp[t[i]]==0){
                    mpp.erase(t[i]);
                }
            }
            else{
                return false;
            }
        }
        if(!mpp.empty()) return false;
        return true;
    }
};
