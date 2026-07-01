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
    ListNode* f(ListNode* node1,ListNode* node2){
        ListNode* ptr1=node1;
        ListNode* ptr2=node2;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* ans=dummyNode;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val<ptr2->val){
                dummyNode->next=ptr1;
                dummyNode=dummyNode->next;
                ptr1=ptr1->next;
            }
            else{
                dummyNode->next=ptr2;
                dummyNode=dummyNode->next;
                ptr2=ptr2->next;
            }
        }
        if(ptr1!=NULL){
            dummyNode->next=ptr1;
        }
        if(ptr2!=NULL){
            dummyNode->next=ptr2;
        }
        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        ListNode* ans=lists[0];
        for(int i=1;i<n;i++){
            ListNode* temp1=lists[i];
            ans=f(ans,temp1);
        }
        return ans;
    }
};
