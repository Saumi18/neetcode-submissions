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
        if (head == NULL || head->next == NULL || head->next->next ==NULL)
            return;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // +1
            fast = fast->next->next;    // +2
        }
        ListNode* h1 = head;
        ListNode* t1 = slow;
        ListNode* h2 = slow->next;
        ListNode* t2 = fast;
        t1->next = NULL;

        ListNode* temp2 = h2->next;
        ListNode* temp1 = h2;
        temp1->next = NULL;
        while(temp2!=NULL){
            ListNode* temp3  = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
        }
        h2 = temp1;
        ListNode* s1 = h1;
        ListNode* s2 = h2;
        while(s1!=NULL && s2!=NULL){
            ListNode* next1 = s1->next;
            ListNode* next2 = s2->next;
            s1->next = s2;
            s2->next = next1;
            s1 = next1;
            s2 = next2;
        }
    }
};
