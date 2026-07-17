struct TrieNode
{
    TrieNode()
    {
        this->c = '?';
        this->isEnd = false;
    }

    TrieNode(char c, bool isEnd)
    {
        this->c = c;
        this->isEnd = isEnd;
    }

    char c;
    bool isEnd;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    TrieNode* head = new TrieNode();
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        res.clear(); 
        //add all words to trie
        for (string s : words)
        {
            TrieNode* curr = head;
            for (char c : s)
            {
                if (!curr->children.contains(c)) curr->children[c] = new TrieNode(c, false); 

                curr = curr->children[c];
            }

            curr->isEnd = true;
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string word = "";
        
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].size(); col++)
            {
                dfs(head, board, visited, row, col, word);
            }
        }

        return res;
    }

    void dfs(TrieNode* curr, vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string& word)
    {
        if (!isInBounds(board, row, col)) return;
        if (!curr->children.contains(board[row][col])) return;
        
        visited[row][col] = true;
        word.push_back(board[row][col]);
        
        if (curr->children[board[row][col]]->isEnd)
        {
            res.push_back(word);
            curr->children[board[row][col]]->isEnd = false;
        } 

        if (isInBounds(board, row - 1, col) && !visited[row - 1][col]) dfs(curr->children[board[row][col]], board, visited, row - 1, col, word);
        if (isInBounds(board, row + 1, col) && !visited[row + 1][col]) dfs(curr->children[board[row][col]], board, visited, row + 1, col, word);
        if (isInBounds(board, row, col - 1) && !visited[row][col - 1]) dfs(curr->children[board[row][col]], board, visited, row, col - 1, word);
        if (isInBounds(board, row, col + 1) && !visited[row][col + 1]) dfs(curr->children[board[row][col]], board, visited, row, col + 1, word);
        
        visited[row][col] = false;
        word.pop_back();
    }

    bool isInBounds(vector<vector<char>>& board, int row, int col)
    {
        if (row < 0) return false;
        if (col < 0) return false;
        if (row >= board.size()) return false;
        if (col >= board[0].size()) return false;

        return true;
    }
};
