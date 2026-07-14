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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root==NULL){
            ans+="#N";
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sze = q.size();
            for (int i = 0; i < sze; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node==NULL){
                    ans+="#N";
                }
                else{
                    ans+="#"+to_string(node->val);
                        q.push(node->left);
                        q.push(node->right);
                }
            }
        }
        return ans;
    }

    string f(string data, int &i) {
        string ans = "";
        while (i<data.size() && data[i] != '#') {
            ans += data[i];
            i++;
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        int i = 1;
        string ans = f(data, i);
        TreeNode* root;
        if (ans == "N") {
            return NULL;
        } else {
            root=new TreeNode(stoi(ans));
        }
        queue<TreeNode*> q;
        q.push(root);
        i++;
        while(!q.empty() && i<data.size()){
            TreeNode* node=q.front();
            q.pop();
            string getString=f(data,i);
            if(getString=="N"){
                node->left=NULL;
            }
            else{
                node->left=new TreeNode(stoi(getString));
                q.push(node->left);
            }
            i++;
            if(i<data.size()){
                string getString1=f(data,i);
                if(getString1=="N"){
                    node->right=NULL;
                }
                else{
                    node->right=new TreeNode(stoi(getString1));
                    q.push(node->right);
                }
                i++;
            }

        }
        return root;
    }
};
