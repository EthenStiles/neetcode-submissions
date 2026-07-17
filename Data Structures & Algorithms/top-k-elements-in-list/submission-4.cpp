class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m; //value, frequency
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        vector<int> result;

        // Step 1: count frequencies
        for (int num : nums) m[num]++;

        for (auto& p : m) buckets[p.second].push_back(p.first);
            
        for (int i = buckets.size() - 1; i >= 0; i--)
        {
            vector<int> bucket = buckets[i];
            
            for (int x : bucket)
            {
                result.push_back(x);
                k--;

                if (k == 0) return result;
            }
        }

        return result;
    }
};
