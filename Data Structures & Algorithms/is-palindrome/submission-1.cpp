class Solution {
public:
    bool isPalindrome(string s) 
    {
        string cmp;
        for (char c : s) if (isalpha(c) || isdigit(c)) cmp.push_back(tolower(c));
        
        int left = 0; 
        int right = cmp.length() - 1;

        while (left < right)
        {
            if (tolower(cmp[left]) != tolower(cmp[right])) return false;
            
            left++;
            right--;
        }

        return true;
    }
};
