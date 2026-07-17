class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res = 0;
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        unordered_set<int> s;
        int conseq = 0;

        for (int n : nums)
        {
            maxNum = max(n, maxNum);
            minNum = min(n, minNum);
            s.insert(n);
        }

        for (int n = minNum; n <= maxNum; n++)
        {
            if (s.contains(n)) conseq++;
            else conseq = 0;
            res = max(res, conseq);
        } 

        return res;  
    }
};
