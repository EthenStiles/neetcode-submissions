class Solution {
public:
    string curr;
    vector<string> res;
    vector<string> generateParenthesis(int n) 
    {
        dfs(n, 0, 0);
        return res;
    }

    void dfs(int n, int numOpen, int numClose)
    {
        if (curr.size() == n * 2)
        {
            res.push_back(curr);
            return;
        }

        if (numOpen < n)
        {
            curr.push_back('(');
            dfs(n, numOpen + 1, numClose);
            curr.pop_back();
        }
        
        if (numOpen > numClose && numClose < n)
        {
            curr.push_back(')');
            dfs(n, numOpen, numClose + 1);
            curr.pop_back();
        }
    }
};
