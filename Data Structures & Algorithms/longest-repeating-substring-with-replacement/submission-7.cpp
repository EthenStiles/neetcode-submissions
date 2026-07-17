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
            
            arr[s[right] - 'A']++;
            
            for (int i = 0; i < 26; i++)
            {
                if (arr[i] > mostCommonCharCount)
                {
                    mostCommonCharCount = arr[i];
                    mostCommonChar = i + 'A';
                }
            }
            
            if (k >= (right - left + 1) - mostCommonCharCount)
            {
                res = max(res, right - left + 1);
            }
                
            while (k < (right - left + 1) - mostCommonCharCount)
            {
                arr[s[left] - 'A']--;
                left++;

                if (k >= (right - left + 1) - mostCommonCharCount) break;
                
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
