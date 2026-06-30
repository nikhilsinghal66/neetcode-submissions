class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n - 1;
        int leftmax = 0;
        int rightmax = 0;
        int ans = 0;
        while (low < high) {
            if (height[low] < height[high]) {
                if (height[low] >= leftmax) {
                    leftmax = height[low];
                } else {
                    ans += leftmax - height[low];
                }
                low++;
            } else {
                if (height[high] >= rightmax) {
                    rightmax = height[high];
                } else {
                    ans += rightmax - height[high];
                }
                high--;
            }
        }
        return ans;
    }
};
