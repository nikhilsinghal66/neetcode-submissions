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
    bool f(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }
        if(!root || !subRoot){
            return false;
        }
        return root->val==subRoot->val && f(root->left,subRoot->left) && f(root->right,subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        bool left=isSubtree(root->left,subRoot);
        if(root->val==subRoot->val){
            if(f(root,subRoot)){
                return true;
            }
        }
        bool right=isSubtree(root->right,subRoot);
        return left || right;
    }
};
