class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int res = 0;
        
        for (int i = 0; i < heights.size(); i++)
        {
            int curr = heights[i];
            int left = i - 1;
            int right = i + 1;

            while (left >= 0 && heights[left] >= curr) left--;
            while (right < heights.size() && heights[right] >= curr) right++;
            

            res = max(res, curr * (right - left - 1));
        }

        return res;
    }
};
