class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1) fresh++;
                
                if (grid[row][col] == 2)
                {
                    q.push({row, col});
                } 
            } 
        }

        if (fresh == 0) return 0;

        //bfs
        int minutes = 0;
        while (!q.empty())
        {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (grid[row][col] == 0) continue;
                
                addOrange(row - 1, col, q, grid, fresh);
                addOrange(row + 1, col, q, grid, fresh);
                addOrange(row , col - 1, q, grid, fresh);
                addOrange(row , col + 1, q, grid, fresh); 
            }

            minutes++; 
        }

        return (fresh == 0) ? minutes - 1 : -1;
    }

    void addOrange(int row, int col, queue<pair<int, int>>& q, vector<vector<int>>& grid, int& fresh)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1) return;
        q.push({row, col});
        grid[row][col] = 2;
        fresh--;
    }
};
