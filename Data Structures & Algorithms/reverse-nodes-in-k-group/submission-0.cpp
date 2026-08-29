class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* prevGroup = NULL;

        while (start != NULL) {
            ListNode* end = start;
            int count = 1;

            while (count < k && end != NULL) {
                end = end->next;
                count++;
            }
            if (end == NULL)
                break;

            ListNode* nextGroup = end->next;
            ListNode* prev = nextGroup;
            ListNode* curr = start;

            while (curr != nextGroup) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            if (prevGroup != NULL)
                prevGroup->next = end;
            else
                head = end;
            prevGroup = start;
            start = nextGroup;
        }
        return head;
    }
};