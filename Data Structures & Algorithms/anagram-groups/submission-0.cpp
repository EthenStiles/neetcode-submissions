class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;

        for (string s : strs)
        {
            string oldString = s;
            sort(s.begin(), s.end());
            if (m.contains(s)) m[s].push_back(oldString);
            else m[s] = {oldString};
        }

        for (auto& pair : m) res.push_back(pair.second);

        return res;
    }
};
