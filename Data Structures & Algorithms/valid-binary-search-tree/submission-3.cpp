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
    bool f(TreeNode* root,int low,int high){
        if(!root){
            return true;
        }
        if(root->val>=high || root->val<=low){
            return false;
        }
        return f(root->left,low,root->val) && f(root->right,root->val,high);
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return f(root,INT_MIN,INT_MAX);
        // bool check=true;
        // bool check1=true;
        // if(root->left && root->left->val>=root->val){
        //     check=false;
        // }
        // if(root->right && root->right->val<=root->val){
        //     check1=false;
        // }
        // isValidBST(root->left);
        // isValidBST(root->right);
        // return check&check1;
    }
};
