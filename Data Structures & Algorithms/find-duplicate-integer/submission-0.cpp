class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> seen;

        for (int n : nums)
        {
            if (seen.contains(n)) return n;
            else seen.insert(n);
        }

        return 0;
        
    }
};
