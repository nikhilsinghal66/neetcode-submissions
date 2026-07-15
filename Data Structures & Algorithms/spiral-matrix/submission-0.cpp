class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int len = (min(n, m) + 1) / 2;
        for(int i=0;i<len;i++){
            for(int j=i;j<=m-i-1;j++){
                ans.push_back(matrix[i][j]);
            }
            for(int j=i+1;j<=n-i-2;j++){
                ans.push_back(matrix[j][m-i-1]);
            }
            if(i != n-i-1){
            for(int j=m-i-1;j>=i;j--){
                ans.push_back(matrix[n-i-1][j]);
            }

            }
            if(i != m-i-1){
            for(int j=n-i-2;j>i;j--){
                ans.push_back(matrix[j][i]);
            }
            }
        }
        return ans;
    }
};
