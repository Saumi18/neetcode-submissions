class Solution {
    vector<int> parent;

    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = n;
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        for(auto& edge: edges){
            int a = find(edge[0]);
            int b = find(edge[1]);
            if(a == b) continue;
            parent[b] = a;
            cnt--;
        }
        return cnt;
    }
};
