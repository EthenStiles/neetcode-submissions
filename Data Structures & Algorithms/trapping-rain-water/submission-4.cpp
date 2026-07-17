class Solution {
public:
    int trap(vector<int>& height) 
    {
        int water = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];

        while (l < r)
        {
            if (maxL < maxR)
            {
                l++;
                water += max(0, maxL - height[l]);
                maxL = max(maxL, height[l]);
            } 

            else
            {
                r--;
                water += max(0, maxR - height[r]);
                maxR = max(maxR, height[r]);
            }  
        }

        return water;
    }
};
