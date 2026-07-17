class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        vector<int> result;

        // Step 1: count frequencies
        for (int num : nums) freq[num]++;
            
        priority_queue<pair<int, int>> maxHeap;

        for (auto& p : freq)
        {
            maxHeap.push({p.second, p.first}); // (frequency, value)
        }

        while (k > 0)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }

        return result;
    }
};
