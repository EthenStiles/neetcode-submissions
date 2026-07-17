class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int> m;
        for (char c : s1) m[c]++;

        for (int left = 0; left < s2.size(); left++)
        {
            if (m.contains(s2[left]))
            {
               unordered_map<char, int> temp = m;

                for (int right = left; right < s2.size(); right++)
                {
                    if (temp.contains(s2[right]) && temp[s2[right]] > 0)
                    {
                        temp[s2[right]]--;
                    }

                    else break;  
                } 

                if (checkMapAllZero(temp)) return true;
            }
        }

        return false;
    }

    bool checkMapAllZero(unordered_map<char, int>& m)
    {
        for (auto p : m)
        {
            if (p.second != 0) return false;
        }

        return true;
    }
};
