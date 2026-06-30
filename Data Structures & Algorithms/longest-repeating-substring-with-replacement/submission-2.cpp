class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> str(26,0);
        int l=0;
        int maxfreq=0;
        int ans=0;
        for(int i=0;i<n;i++){
            str[s[i]-'A']++;
            maxfreq=max(maxfreq,str[s[i]-'A']);
            while((i-l+1)-maxfreq >k){
                str[s[l]-'A']--;
                l++;
            }
            ans=max(ans,(i-l+1));
        }
        return ans;
    }
};
