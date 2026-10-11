class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(fresh > 0 && !q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(const auto& d:dir){
                    int row = r + d.first;
                    int col = c + d.second;
                    if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh == 0) return time;
        else return -1;
    }
};
