class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;

        // Step 1: count frequencies
        for (int num : nums) freq[num]++;
            
        // Step 2: move into vector
        vector<pair<int, int>> elems;
        for (auto& p : freq) elems.push_back(p);
            

        // Step 3: sort by frequency (descending)
        sort(elems.begin(), elems.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        // Step 4: take first k elements
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(elems[i].first);

        return result;
    }
};
