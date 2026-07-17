class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int left = 0;
        int right = heights.size() - 1;
        int water = 0;
        
        while (left < right)
        {
            water = max(water, min(heights[left], heights[right]) * (right - left));

            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return water;
    }
};
