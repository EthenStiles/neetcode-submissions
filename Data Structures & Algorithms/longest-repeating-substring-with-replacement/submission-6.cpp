class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int left = 0;
        int res = 0;
        int arr[26] = {};
       
        for (int right = 0; right < s.length(); right++)
        {
            int mostCommonCharCount = 0;
            char mostCommonChar = '1';
            char rightChar = s[right];
            char leftChar = s[left];
            int windowLen = right - left + 1;
            
            arr[rightChar - 'A']++;
            
            for (int i = 0; i < 26; i++)
            {
                if (arr[i] > mostCommonCharCount)
                {
                    mostCommonCharCount = arr[i];
                    mostCommonChar = i + 'A';
                }
            }
            
            if (k >= windowLen - mostCommonCharCount)
            {
                res = max(res, windowLen);
            }
                
            while (k < windowLen - mostCommonCharCount)
            {
                leftChar = s[left];
                arr[leftChar - 'A']--;
                left++;

                windowLen = right - left + 1;
                if (k >= windowLen - mostCommonCharCount) break;
                
                for (int i = 0; i < 26; i++)
                {
                    if (arr[i] > mostCommonCharCount)
                    {
                        mostCommonCharCount = arr[i];
                        mostCommonChar = i + 'A';
                    }
                }  
            } 
        }
        
        return res;
    }
};
