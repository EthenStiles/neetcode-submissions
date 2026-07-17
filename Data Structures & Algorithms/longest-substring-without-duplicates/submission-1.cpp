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

            //cout << "After Insert" << endl;
            //for (auto c : seen) cout << c << ", ";
            //cout << endl;

            res = max(res, static_cast<int>(seen.size()));
            seen.erase(s[left]);

           // cout << "After Erase" << endl;
            //for (auto c : seen) cout << c << ", ";
            //cout << endl;
            
            left++; 
        }

        return res;
    }
};
