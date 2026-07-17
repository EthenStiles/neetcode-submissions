class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int target;
    KthLargest(int k, vector<int>& nums) 
    {
        target = k;
        for (int n : nums) pq.push(n);
        while (pq.size() > target) pq.pop();
    }
    
    int add(int val) 
    {
        pq.push(val);
        if (pq.size() > target) pq.pop();
        return pq.top();
    }
};
