/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* dummyNode=new Node(-1);
        Node* ans=dummyNode;
        unordered_map<Node*,Node*> mpp;
        while(temp!=NULL){
            Node* copy1=new Node(temp->val);
            mpp[temp]=copy1;
            dummyNode->next=copy1;
            dummyNode=dummyNode->next;
            temp=temp->next;
        }
        dummyNode=ans->next;
        temp=head;
        while(temp!=NULL){
            dummyNode->random=mpp[temp->random];
            dummyNode=dummyNode->next;
            temp=temp->next;
        }
        return ans->next;
    }
};
