class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> temp;

        for (int x : nums1) temp.push_back(x);
        for (int x : nums2) temp.push_back(x);

        sort(temp.begin(), temp.end());

        if (temp.size() % 2 == 0) return double((temp[temp.size() / 2]) + temp[(temp.size() / 2) - 1]) / 2;
        return temp[temp.size() / 2];
        
        
    }
};
