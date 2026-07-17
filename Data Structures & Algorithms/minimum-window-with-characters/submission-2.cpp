class Solution {
public:
    string minWindow(string s, string t) 
    {
        string res = "";
        if (t.length() > s.length()) return res;
        unordered_map<char, int> tCounter;

        for (char c : t)
        {
            tCounter[c]++;
        }

        for (int i = 0; i <= s.length() - t.length(); i++)
        {
            int left = 0;
            int right;
            unordered_map<char, int> subMap;
            deque<char> candidate;
            
            //create map for current substring size and update candidate
            for (right = 0; right < t.size() + i; right++)
            {
                subMap[s[right]]++;
                candidate.push_back(s[right]);
            }

            //count matches between current substring and t
            int matches = 0;
            for (auto p : tCounter)
            {
                if (subMap[p.first] >= p.second) matches++;
            }

            if (matches == tCounter.size())
            {
                return string(candidate.begin(), candidate.end());  
            }
           
            bool foundMatch = false;
            
            //cout << "Window Size : " << right - left << endl;
            //cout << "----------------------" << endl;
            while (right < s.length())
            {
                if (matches == tCounter.size()) break;
                
                //for (char c : candidate) cout << c;
               // cout << " Matches: " << matches << endl;
                
                //remove left
                char leftChar = s[left];
                subMap[leftChar]--;
                candidate.pop_front();

                if (tCounter.contains(leftChar))
                {
                    //if (subMap[leftChar] >= tCounter[leftChar]) matches++;
                    if (subMap[leftChar] + 1 == tCounter[leftChar]) matches--;
                }
                
                //add right
                char rightChar = s[right];
                subMap[rightChar]++;
                candidate.push_back(rightChar);

                if (tCounter.contains(rightChar))
                {
                    if (subMap[rightChar] == tCounter[rightChar]) matches++;
                    //else if (subMap[rightChar] - 1 == tCounter[rightChar]) matches--;
                }

                left++;
                right++;
            }

            if (matches == tCounter.size())
            {
                //cout << "found" << endl;
                return string(candidate.begin(), candidate.end());  
            }  
        }
        
        return res;
    }
};
