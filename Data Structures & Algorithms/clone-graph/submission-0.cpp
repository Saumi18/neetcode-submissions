/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* dfs(Node* node, map<Node*,Node*>& oldToNew){
        if(!node) return NULL;
        if(oldToNew.count(node)){
            return oldToNew[node];
        }
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        for(Node* neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor,oldToNew));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldToNew;
        return dfs(node, oldToNew);
    }
};
