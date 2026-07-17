class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        
        int left = 0;
        for (int right = 0; right <= n; right++)
        { 
            if (right >= k)
            {
                while (pq.top().second < left) pq.pop();
                res.push_back(pq.top().first);
                left++;
            }

            //cout << right << endl;
            cout << nums[right] << endl;
            pq.emplace(nums[right], right);   
        }

        return res;   
    }
};
