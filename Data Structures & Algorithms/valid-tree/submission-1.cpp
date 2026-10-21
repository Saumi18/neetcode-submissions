class Solution {
    vector<int> parent;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // For valid tree cond 1 : All nodes should be connected and for that edges should be n-1
        if(edges.size() != n-1) return false;

        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(auto& edge: edges){
            int a = find(edge[0]);
            int b = find(edge[1]);
            if(a==b) return false;
            parent[b] = a;
        }
        return true;
    }
};
