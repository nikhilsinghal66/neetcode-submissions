/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //Read and understand carefully...
    unordered_map<Node*,Node*> mpp;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(mpp.find(node)!=mpp.end()){
            return mpp[node];
        }
        Node* clone=new Node(node->val);
        mpp[node]=clone;
        for(Node* newNode:node->neighbors){
            clone->neighbors.push_back(cloneGraph(newNode));
        }
        return clone;
    }
};
