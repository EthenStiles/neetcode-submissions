class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for (char c : s) m1[c]++;
        
        for (char c : t) m2[c]++;
        
        for (auto& pair : m1)
        {
            if (m2[pair.first] != pair.second) return false;
        }

        return true;  
    }
};
