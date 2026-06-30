class Solution {
   public:
    int trap(vector<int>& height) {
        // Prefix_sum && Suffix_sum...
        int n = height.size();
        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);
        prefixSum[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = max(prefixSum[i - 1], height[i]);
        }
        suffixSum[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = max(suffixSum[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(prefixSum[i], suffixSum[i]) - height[i];
        }
        return ans;
    }
};
