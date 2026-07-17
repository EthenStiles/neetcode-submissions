class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        unordered_map<int, int> m;

        for (char c : s) m[c]++;
        
        for (char c : t)
        {
            if (m[c] == 0) return false;
            else m[c]--;
        } 
        
        return true;  
    }
};
