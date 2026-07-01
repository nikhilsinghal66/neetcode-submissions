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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* dummynode=new ListNode(-1);
        ListNode* head3=dummynode;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                ListNode* temp=head1;
                dummynode->next=temp;
                head1=head1->next;
                dummynode=dummynode->next;
            }
            else{
                ListNode* temp=head2;
                dummynode->next=temp;
                head2=head2->next;
                dummynode=dummynode->next;
            }
        }
        if(head1==NULL){
            dummynode->next=head2;
        }
        else{
            dummynode->next=head1;
        }
        return head3->next;
    }
};
