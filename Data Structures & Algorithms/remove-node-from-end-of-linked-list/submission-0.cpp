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
        ListNode* temp = head;
        int m = 0;
        while(temp!=NULL){
            m++;
            temp = temp->next;
        }
        if(m==n) return head->next;
        int cnt = 1;
        temp = head;
        while(cnt != m-n){
            temp = temp->next;
            cnt++;
        }
        ListNode* t1 = temp->next;
        ListNode* t2 = temp->next->next;
        temp->next = t2;
        return head;
    }
};
