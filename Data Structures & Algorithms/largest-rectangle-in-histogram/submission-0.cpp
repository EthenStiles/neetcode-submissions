class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int res = 0;
        
        for (int i = 0; i < heights.size(); i++)
        {
            int curr = heights[i];
            int left = i - 1;
            int leftSum = 0;
            int right = i + 1;
            int rightSum = 0;

            while (left >= 0 && heights[left] >= curr)
            {
                leftSum += curr;
                left--;
            }

            while (right < heights.size() && heights[right] >= curr)
            {
                rightSum += curr;
                right++;
            }

            res = max(res, curr + leftSum + rightSum);
        }

        return res;
    }
};
