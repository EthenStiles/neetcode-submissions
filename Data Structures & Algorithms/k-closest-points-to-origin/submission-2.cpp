class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> res;
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, less<pair<float, vector<int>>>> minHeap;
        
        for (auto& point : points) 
        {
            float xDist = point[0] * point[0];
            float yDist = point[1] * point[1];
            float distance = sqrt(xDist + yDist);
            minHeap.push({distance, point});
            if (minHeap.size() > k) minHeap.pop();
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
