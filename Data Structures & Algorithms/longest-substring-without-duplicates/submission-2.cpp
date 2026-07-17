class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_set<char> seen;

        while (right < s.length())
        {
            while (right < s.length() && !seen.contains(s[right]))
            {
                seen.insert(s[right]);
                right++;
                
            }

            res = max(res, static_cast<int>(seen.size()));

            seen.erase(s[left]);
            left++;    
        }

        return res;
    }
};
