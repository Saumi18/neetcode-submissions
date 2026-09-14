class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0){
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs(grid,r+1,c) + dfs(grid,r-1,c) + dfs(grid,r,c+1) + dfs(grid,r,c-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c] == 1){
                    area = max(area,dfs(grid,r,c));
                }
            }
        }
        return area;
    }
};
