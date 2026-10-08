class Solution {
    vector<int> parent;
    vector<int> rank;
public:
    int find(int x) {
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(auto& edge : edges){
            if(!unite(edge[0], edge[1])){
                return edge;
            }
        }
        return {};
    }
};