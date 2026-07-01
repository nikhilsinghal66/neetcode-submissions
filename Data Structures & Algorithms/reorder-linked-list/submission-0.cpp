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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        stack<ListNode*> st;
        while (temp != NULL) {
            n++;
            st.push(temp);
            temp = temp->next;
        }
        ListNode* ans = head;
         for (int i = 0; i < n / 2 ; i++) {
            ListNode* temp1 = head->next;
            head->next = st.top();
            st.pop();
            head = head->next;
            head->next = temp1;
            head = head->next;
        }
        head->next = NULL;
        head = ans;
    }
};
