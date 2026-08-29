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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* h3 = new ListNode(0);
        ListNode* temp = h3;
        while(h1!= NULL || h2!=NULL || carry!=0){
            int sum  = carry;
            if(h1!=NULL){
                sum += h1->val;
                h1 = h1->next;
            }
            if(h2!=NULL){
                sum+= h2->val;
                h2 = h2->next;
            }
            temp->next = new ListNode(sum%10);
            carry = sum/10;
            temp = temp->next;
        }
        return h3->next;
    }
};
