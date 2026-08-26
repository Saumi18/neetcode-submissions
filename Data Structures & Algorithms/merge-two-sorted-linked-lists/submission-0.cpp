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
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;
        
        ListNode* head;
        ListNode* tail;

        if (h1->val <= h2->val) {
            head = h1;
            tail = h1;
            h1 = h1->next;
        }
        else {
            head = h2;
            tail = h2;
            h2 = h2->next;
        }
        while(h1 != NULL && h2 != NULL){
            if(h1->val <= h2->val){
                tail->next = h1;
                tail = h1;
                h1 = h1->next;
            }
            else{
                tail->next = h2;
                tail = h2;
                h2  = h2->next;
            }
        }
        tail->next = h1 ? h1 : h2; // Once any LL becomes NULL so we attach the other remaining after tail
        return head;
    }
};
