class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for(int i=0;i<m;i++){
            need[t[i]]++;
        }
        int required=need.size();
        int have=0;
        int start=0;
        int l=0;
        int minlen=INT_MAX;
        for(int i=0;i<n;i++){
            window[s[i]]++;
            if(need.count(s[i])&& window[s[i]]==need[s[i]]){
                have++;
            }
            while(have==required){
                if((i-l+1)<minlen){
                    minlen=i-l+1;
                    start=l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]]<need[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};
