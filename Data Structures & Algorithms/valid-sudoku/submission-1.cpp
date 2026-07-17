class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        return checkCols(board) && checkRows(board) && checkBoxes(board);
    }

    bool checkCols(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            bool arr[9] = {};
            
            for (int j = 0; j < 9; j++)
            {
                char x = board[j][i];
                if (x == '.') continue;

                int elt = x - '0';
                
                if (arr[elt - 1] == true) return false;
                else arr[elt - 1] = true;
            }
        }

        return true;
    }


    bool checkRows(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            bool arr[9] = {};
            
            for (int j = 0; j < 9; j++)
            {
                char x = board[i][j];
                if (x == '.') continue;

                int elt = x - '0';

                if (arr[elt - 1] == true) return false;
                else arr[elt - 1] = true;
            }
        }

        return true;
    }
    
    bool checkBoxes(vector<vector<char>>& board)
    {
        for (int i = 0; i <= 6; i += 3)
        {
            for (int j = 0; j <= 6; j += 3)
            {
                bool arr[9] = {};

                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        char x = board[k + i][l + j];
                        if (x == '.') continue;

                        int elt = x - '0';

                        if (arr[elt - 1] == true) return false;
                        else arr[elt - 1] = true;
                    }
                }
            } 
        }

        return true;
    }
};
