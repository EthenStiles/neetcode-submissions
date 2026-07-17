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

        for (int n : nums)
        {
            if (!s.contains(n - 1))
            {
                int x = n;

                while (s.contains(x))
                {
                    conseq++;
                    res = max(res, conseq);
                    x++;
                }
            }

            conseq = 0;
        } 

        return res;  
    }
};
