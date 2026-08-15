class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        { 
            dfs(i, 0, board, visited); //left border
            dfs(i, board[0].size() - 1, board, visited); //right border
        }

        for (int i = 0; i < board[0].size(); i++)
        {
            dfs(0, i, board, visited); //top border
            dfs(board.size() - 1, i, board, visited); //bottom border
        }

        
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (row > 0 && col > 0 && row < board.size() - 1 && col < board[0].size() - 1)
                {
                    if (board[row][col] == 'O') board[row][col] = 'X';
                    if (board[row][col] == 'N') board[row][col] = 'O';
                }
            }
        }

       // printBoard(board);
    }

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return;
        
        if (board[row][col] == 'N' || board[row][col] == 'X' || visited[row][col]) return;

        if (row > 0 && col > 0 && row < board.size() - 1 && col < board[0].size() - 1) board[row][col] = 'N';
        visited[row][col] = true;

        dfs(row - 1, col, board, visited); //up
        dfs(row + 1, col, board, visited); //down
        dfs(row, col - 1, board, visited); //left
        dfs(row, col + 1, board, visited); //right
    }

    void printBoard(vector<vector<char>>& board)
    {
        for (int row = 0; row < board.size(); row++)
        {
            cout << "[";
            for (int col = 0; col < board[0].size(); col++)
            {
                if (col < board[0].size() - 1) cout << board[row][col] << ", ";
                else cout << board[row][col];
            }

            cout << "]" << endl;
        }
    }
};
