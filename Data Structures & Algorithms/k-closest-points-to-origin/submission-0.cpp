class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> res;
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, greater<pair<float, vector<int>>>> minHeap;
        
        for (auto& point : points) 
        {
            float xDist = point[0] * point[0];
            float yDist = point[1] * point[1];
            float distance = sqrt(xDist + yDist);
            cout << distance << " = " << point[0] << "," << point[1] << endl;
            minHeap.push({distance, point});
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
