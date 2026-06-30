class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int low=0;
        int high=n-1;
        int ans=INT_MIN;
        while(low<high){
            int temp=min(heights[low],heights[high]);
            ans=max(ans,temp*(high-low));
            if(heights[low]<heights[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};
