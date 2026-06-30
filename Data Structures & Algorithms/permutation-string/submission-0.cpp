class Solution {
public:
    bool f(int ind, string &s1,string &s2,unordered_map<char,int> mpp){
        int n=s1.size();
        int m=s2.size();
        for(int i=ind;i<ind+n;i++){
            if(mpp.find(s2[i])==mpp.end()){
                return false;
            }
            else{
                mpp[s2[i]]--;
                if(mpp[s2[i]]==0){
                    mpp.erase(s2[i]);
                }
            }
        }
        if(mpp.empty()) return true;
        return false;
    }

    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s1[i]]++;
        }
        bool ans=false;
        for(int i=0;i<m;i++){
            if(mpp.find(s2[i])!=mpp.end()){
                if(f(i,s1,s2,mpp)==true){
                    return true;
                }
            }
        }
        return false;
    }
};
