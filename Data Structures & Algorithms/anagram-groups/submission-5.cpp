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
        int arr[27] = {};

        for (char c : a) arr[c - 'a']++;
    
        for (char c : b)
        {
            if (arr[c - 'a'] == 0) return false;
            else arr[c - 'a']--;
        }

        return true;
    }
};
