class Solution {
public:
    int trap(vector<int>& height) 
    {
        int water = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            int maxRight = 0;
            int maxLeft = 0;

            for (int left = i - 1; left >= 0; left--) 
                maxLeft = max(maxLeft, height[left]);

            for (int right = i + 1; right < height.size(); right++)
                maxRight = max(maxRight, height[right]);
            
            cout << water << endl;
            int currWater = min(maxLeft, maxRight) - height[i]; 
            water = (currWater > 0) ? water + currWater : water;   
        }

        return water;
    }
};
