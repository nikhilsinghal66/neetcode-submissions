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
    TreeNode* f(unordered_map<int,int> &mpp,int &preOrderIndex,vector<int>&preorder,
    vector<int> &inorder,int left,int right){
        if(left>right){
            return NULL;
        }
        int root1=preorder[preOrderIndex];
        preOrderIndex++;
        int index=mpp[root1];
        TreeNode* root=new TreeNode(root1);
        root->left=f(mpp,preOrderIndex,preorder,inorder,left,index-1);
        root->right=f(mpp,preOrderIndex,preorder,inorder,index+1,right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int preorderIndex=0;
        return f(mpp,preorderIndex,preorder,inorder,0,inorder.size()-1);
    }
};
