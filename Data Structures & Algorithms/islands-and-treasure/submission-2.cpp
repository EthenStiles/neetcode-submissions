class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 0)
                {
                    q.push({row, col});
                    visited[row][col] = true;
                } 
            }
        }

        int dist = 0;
        while (!q.empty())
        {
            int row, col;
            int qSize = q.size();
            
            for (int i = 0; i < qSize; i++)
            {
                pair<int, int> p = q.front();
                q.pop();
                row = p.first;
                col = p.second;

                grid[row][col] = dist;

                addTile(row + 1, col, visited, q, grid);
                addTile(row - 1, col, visited, q, grid);
                addTile(row, col + 1, visited, q, grid);
                addTile(row, col - 1, visited, q, grid);
            }

            dist++; 
        }
    }

    void addTile(int row, int col, vector<vector<bool>>& visited, queue<pair<int, int>>& q, vector<vector<int>>& grid)
    {
        if (row < 0 || col < 0 || row >= visited.size() || col >= visited[0].size()) return;
        if (visited[row][col]) return;
        if (grid[row][col] == -1) return;

        visited[row][col] = true;
        q.push({row, col});
    }

};
