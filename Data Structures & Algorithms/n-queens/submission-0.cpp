struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        std::size_t h1 = std::hash<int>{}(p.first);
        std::size_t h2 = std::hash<int>{}(p.second);
        
        // Use a golden-ratio-based combination to prevent collisions
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class Solution {
public:
    vector<string> curr;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) 
    {
        unordered_map<pair<int, int>, int, PairHash> used;
        unordered_set<pair<int, int>, PairHash> queenLocs;
       
        string rowString = "";
        for (int i = 0; i < n; i++)
        {
            rowString.push_back('.');
        }
        
        dfs(n, 0, rowString, used);

        return res;   
    }

    void dfs(int n, int row, string& rowString, unordered_map<pair<int, int>, int, PairHash>& used)
    {
        if (row == n)
        {
            res.push_back(curr);
            //if (curr.size() == n)
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (used[{row, i}] > 0) continue;

            markUsed(n, i, row, used);
            string temprowString = rowString;
            temprowString[i] = 'Q';
            curr.push_back(temprowString);
            dfs(n, row + 1, rowString, used);
            curr.pop_back();
            unmarkUsed(n, i, row, used);
        }
    }

    void markUsed(int n, int x, int y, unordered_map<pair<int, int>, int, PairHash>& used)
    {
        for (int i = 0; i < n; i++)
        {
            used[{y, i}]++;
            used[{i, x}]++;

            if (y - i >= 0)
            {
                if (x - i >= 0)
                {
                    used[{y - i, x - i}]++;
                } 

                if (x + i < n)
                {
                   used[{y - i, x + i}]++; 
                } 
            }
            
            if (y + i < n)
            {
                if (x + i < n)
                {
                    used[{y + i, x + i}]++; 
                }

                if (x - i >= 0)
                {
                    used[{y + i, x - i}]++; 
                } 
            }
        }
    }

    void unmarkUsed(int n, int x, int y, unordered_map<pair<int, int>, int, PairHash>& used)
    {
        for (int i = 0; i < n; i++)
        {
            used[{y, i}]--; // row
            used[{i, x}]--; // column

            if (y - i >= 0)
            {
                if (x - i >= 0)
                {
                    used[{y - i, x - i}]--;
                } 

                if (x + i < n)
                {
                   used[{y - i, x + i}]--; 
                } 
            }
            
            if (y + i < n)
            {
                if (x + i < n)
                {
                    used[{y + i, x + i}]--; 
                }

                if (x - i >= 0)
                {
                    used[{y + i, x - i}]--; 
                } 
            }
        }
    }
};
