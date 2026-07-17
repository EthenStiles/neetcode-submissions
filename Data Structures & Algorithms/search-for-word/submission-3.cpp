struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^
               (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                //cout << board[i][j] << endl;

                if (board[i][j] == word[0])
                { 
                    unordered_set<pair<int, int>, pair_hash> explored;
                    explored.insert({i, j});
                    if (checkNext(board, word, 1, i, j, explored)) return true;
                }
            }
        }

        return false;
    }

    bool checkNext(vector<vector<char>>& board, string word, int wordIndex, int i, int j, unordered_set<pair<int, int>, pair_hash>& explored)
    {
        if (wordIndex == word.length()) return true;
        
        char up = (i == 0) ? '?' : board[i - 1][j];
        char right = (j == board[i].size() - 1) ? '?' : board[i][j + 1];
        char down = (i == board.size() - 1) ? '?' : board[i + 1][j];
        char left = (j == 0) ? '?' : board[i][j - 1];

        bool upRes = false;
        bool rightRes = false;
        bool downRes = false;
        bool leftRes = false;

        if (up == word[wordIndex] && !explored.contains({i - 1, j}))
        {
            explored.insert({i - 1, j});
            upRes = true && checkNext(board, word, wordIndex + 1, i - 1, j, explored);
            explored.erase({i - 1, j});
        } 
        
        if (right == word[wordIndex] && !explored.contains({i, j + 1}))
        {
            explored.insert({i, j + 1});
            rightRes = true && checkNext(board, word, wordIndex + 1, i, j + 1, explored);
            explored.erase({i, j + 1});
        } 

        if (down == word[wordIndex] && !explored.contains({i + 1, j}))
        {
            explored.insert({i + 1, j});
            downRes = true && checkNext(board, word, wordIndex + 1, i + 1, j, explored);
            explored.insert({i + 1, j});
        } 

        if (left == word[wordIndex] && !explored.contains({i, j - 1}))
        {
            explored.insert({i, j - 1});
            leftRes = true && checkNext(board, word, wordIndex + 1, i, j - 1, explored);
            explored.erase({i, j - 1});
        } 

        //cout << up << right << down << left << endl;
        return upRes || rightRes || downRes || leftRes;
    }
};
