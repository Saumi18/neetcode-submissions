/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldTocopy;
        oldTocopy[NULL] = NULL;
        Node* curr1 = head;
        while(curr1!=NULL){
            Node* copy = new Node(curr1->val);
            oldTocopy[curr1] = copy;
            curr1 = curr1->next;
        }
        Node* curr2 = head;
        while(curr2!=NULL){
            Node* copy = oldTocopy[curr2];
            copy->next = oldTocopy[curr2->next];
            copy->random  = oldTocopy[curr2->random];
            curr2 = curr2->next;
        }
        return oldTocopy[head];
    }
};
