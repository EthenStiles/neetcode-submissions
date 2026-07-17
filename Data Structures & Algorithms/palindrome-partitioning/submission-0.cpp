class Solution {
public:
    vector<string> part;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) 
    {
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int i)
    {
        if (i >= s.length())
        {
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                part.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--]) return false;
        }

        return true;
    }
};
