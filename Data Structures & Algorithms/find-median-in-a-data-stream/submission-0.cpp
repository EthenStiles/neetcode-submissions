class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        nums.push_back(num);
    }
    
    double findMedian() 
    {
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 != 0) return nums[nums.size() / 2];

        double med = ((double)nums[nums.size() / 2] + (double)nums[(nums.size() / 2) - 1]) / 2;
        return med;
    }
};
