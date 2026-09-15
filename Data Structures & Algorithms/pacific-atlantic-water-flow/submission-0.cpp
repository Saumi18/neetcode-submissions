class Solution {
public:
    int m, n;
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;
        for(auto& d : directions){
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            if(ocean[nr][nc])
                continue;
            if(heights[nr][nc] < heights[r][c])
                continue;
            dfs(heights, nr, nc, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int c = 0; c < n; c++){
            dfs(heights, 0, c, pacific);
            dfs(heights, m - 1, c, atlantic);
        }
        for(int r = 0; r < m; r++){
            dfs(heights, r, 0, pacific);
            dfs(heights, r, n - 1, atlantic);
        }

        vector<vector<int>> ans;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r, c});
                }
            }
        }
        return ans;
    }
};