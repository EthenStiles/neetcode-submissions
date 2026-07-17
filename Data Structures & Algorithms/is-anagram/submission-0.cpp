class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        //unordered_map<int, int> m;

        //for (char c : s)

        return s == t;
        
    }
};
