class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int res = 0;
        
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == '1')
                {
                    res++;
                    dfs(grid, row, col);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if (row < 0 || row > grid.size() - 1 || col < 0 || col > grid[0].size() - 1) return;
        if (grid[row][col] != '1') return;
    
        grid[row][col] = 'x';

        dfs(grid, row - 1, col); //up
        dfs(grid, row + 1, col); //down
        dfs(grid, row, col - 1); //left
        dfs(grid, row, col + 1); //right
    }
};
