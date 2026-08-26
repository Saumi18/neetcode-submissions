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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* t1= head;
        ListNode* t2 = t1->next;
        t1->next = NULL;
        while(t2 != NULL){
            ListNode* t3 = t2->next;
            t2->next =  t1;
            t1=t2;
            t2=t3;
        }
        return t1;
    }
};
