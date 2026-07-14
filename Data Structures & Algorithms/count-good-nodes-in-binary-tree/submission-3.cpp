/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void f(int &ans,TreeNode* root,int max_count){
        if(!root){
            return ;
        }
        if(max_count<=root->val){
            ans++;
            max_count=root->val;
        }
        f(ans,root->left,max_count);
        f(ans,root->right,max_count);
    }

    int goodNodes(TreeNode* root) {
        int ans=0;
        int max_count=root->val;
        f(ans,root,max_count);
        return ans;
    }
};
