class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.length() > s2.length()) return false;
        
        int arr1[26] = {};
        int arr2[26] = {};

        for (int i = 0; i < s1.size(); i++)
        {
           arr1[s1[i] - 'a']++;
           arr2[s2[i] - 'a']++; 
        }

        int matches = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] == arr2[i]) matches++;
        }

        int left = 0;
        for (int right = s1.size(); right < s2.size(); right++)
        {
            if (matches == 26) return true;

            int index = s2[right] - 'a';
            arr2[index]++;
            if (arr2[index] == arr1[index]) matches++;
            else if (arr2[index] == arr1[index] + 1) matches--;

            index = s2[left] - 'a';
            arr2[index]--;
            if (arr2[index] == arr1[index]) matches++;
            else if (arr2[index] == arr1[index] - 1) matches--;

            left++;
        }  

        return matches == 26;
    }
};
