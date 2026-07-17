class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int left = 0;
        int right = heights.size() - 1;

        int water = 0;
        
        while (left < right)
        {
            int minBarHeight = min(heights[left], heights[right]);
            int width = right - left;
            
            water = max(water, minBarHeight * width);

            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return water;
    }
};
