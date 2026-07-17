class KthLargest {
public:
    priority_queue<int> pq;
    int target;
    KthLargest(int k, vector<int>& nums) 
    {
        for (int n : nums) pq.push(n);
        target = k;
    }
    
    int add(int val) 
    {
        pq.push(val);
        priority_queue<int> temp = pq;
        for (int i = 1; i < target; i++) temp.pop();
        return temp.top();
    }
};
