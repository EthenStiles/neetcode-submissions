class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0; 
        int right = s.length() - 1;

        while (left < right)
        {
            while (left < right && !isdigit(s[left]) && !isalpha(s[left])) left++;
            while (left < right && !isdigit(s[right]) && !isalpha(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};
