class Solution {
public:

    string curr;
    vector<string> res;
    unordered_map<char, string> m = 
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) 
    {      
        dfs(digits, 0);
        return res;
    }

    void dfs(string digits, int i)
    {
        if (curr.length() == digits.length())
        {
            if (!curr.empty()) res.push_back(curr);
            return;
        }
        
        string mString = m[digits[i]];
        for (int j = 0; j < mString.length(); j++)
        {
            curr.push_back(mString[j]);
            dfs(digits, i + 1);
            curr.pop_back();
        }
    }
};
