#define INF 2147483647

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 0)
                {
                   //vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                    dfs(grid, row, col, 0);
                }
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int steps)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return; //out of range
        
        if (grid[row][col] == -1) return; //we stepped onto water

        if (grid[row][col] > 0) // if is land
        {
            if (steps >= grid[row][col]) return; // i've played these games before
            grid[row][col] = steps; 
        }

        //visited[row][col] = true; // dont explore the same tile multiple times

        dfs(grid, row - 1, col, steps + 1); //up
        dfs(grid, row + 1, col, steps + 1); //down
        dfs(grid, row, col - 1, steps + 1); //left
        dfs(grid, row, col + 1, steps + 1); //right
    }
};
