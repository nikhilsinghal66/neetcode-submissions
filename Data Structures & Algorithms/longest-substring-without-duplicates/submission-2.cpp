class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Sliding window...
        unordered_map<char,int> mpp;
        int n=s.size();
        int l=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(l<=mpp[s[i]]){
                    l=mpp[s[i]]+1;
                }
            }
            ans=max(ans,i-l+1);
            mpp[s[i]]=i;
        }
        return ans;
    }
};
