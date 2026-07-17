class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder(){}
    
    void addNum(int num) 
    {
        if (minHeap.empty() || num > minHeap.top())
        {
            minHeap.push(num);
        }

        else maxHeap.push(num);
        
        if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        else if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() 
    {
        if ((minHeap.size() + maxHeap.size()) % 2 == 0) return ((double)minHeap.top() + (double)maxHeap.top()) / 2;

        if (maxHeap.size() > minHeap.size()) return (double)maxHeap.top();
        return (double)minHeap.top();
    }
};
