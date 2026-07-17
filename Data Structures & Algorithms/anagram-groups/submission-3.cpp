class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;

        for (string s : strs)
        {
            bool added = false;
            for (auto& vec : res)
            {
                
                if (isAnagram(s, vec[0]))
                {
                    vec.push_back(s);
                    added = true;
                    break;
                }
            }

            if (!added) res.push_back({s}); 
        }
        
        return res;
    }

    bool isAnagram(string a, string b)
    { 
        if (a.length() != b.length()) return false;
        string s1 = a, s2 = b;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
