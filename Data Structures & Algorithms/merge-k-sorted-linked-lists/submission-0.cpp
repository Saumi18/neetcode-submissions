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

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;
        ListNode* head = new ListNode(0);
        for (ListNode* node : lists) {
            if (node != NULL){
                minHeap.push(node);
            }
        }
        ListNode* tail = head;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();
            tail->next = node;
            tail = tail->next;
            if(node->next!=NULL) minHeap.push(node->next);
        }
        return head->next;
    }
};
