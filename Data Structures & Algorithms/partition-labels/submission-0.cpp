class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> firstSeen(26,-1);
        vector<int> lastSeen(26,0);
        set<char> st;
        for(int i=0;i<n;i++){
            if(firstSeen[s[i]-'a']==-1){
                firstSeen[s[i]-'a']=i;
            }
            lastSeen[s[i]-'a']=i;
            st.insert(s[i]);
        }
        vector<pair<int,int>> Interval;
        for(auto it:st){
            Interval.push_back({firstSeen[it-'a'],lastSeen[it-'a']});
        }
        sort(Interval.begin(),Interval.end());
        vector<int> ans;
        pair<int,int> temp=Interval[0];
        for(int i=1;i<Interval.size();i++ ){
            int b1=Interval[i].first;
            int b2=Interval[i].second;
            int a1=temp.first;
            int a2=temp.second;
            if(b1<=a2){
                int val1=min(a1,b1);
                int val2=max(a2,b2);
                temp={val1,val2};
            }
            else{
                ans.push_back(temp.second-temp.first+1);
                temp=Interval[i];
            }
        }
        ans.push_back(temp.second-temp.first+1);
        return ans;
    }
};
