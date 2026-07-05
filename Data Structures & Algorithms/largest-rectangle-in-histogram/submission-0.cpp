class Solution {
public:
    vector<int> find_pse(vector<int> &heights,int n){
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> find_nse(vector<int> &heights,int n){
        vector<int> ans;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(n);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse=find_nse(heights,n);
        vector<int> pse=find_pse(heights,n);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};
