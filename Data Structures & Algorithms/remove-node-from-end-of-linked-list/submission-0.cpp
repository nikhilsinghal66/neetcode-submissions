/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0;
        ListNode* temp=head;
        while(temp!=NULL){
            m++;
            temp=temp->next;
        }
        if(n>m){
            return NULL;
        }
        if(m==1 && n>=1){
            return NULL;
        }
        if(m-n==0){
            return head->next;
        }
        ListNode* prev=NULL;
        temp=head;
        for(int i=0;i<m-n;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        // temp->next=NULL;
        return head;
    }
};
