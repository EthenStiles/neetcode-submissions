class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector<int> maxLeft(height.size(), -1);
        vector<int> maxRight(height.size(), -1);
        vector<int> minLR(height.size(), -1);
        int water = 0;

        int maxHeight = 0;
        for (int i = 0; i < height.size(); i++)
        {
            maxLeft[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }

        maxHeight = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            maxRight[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }

        for (int i = 0; i < height.size(); i++)
        {
            minLR[i] = min(maxLeft[i], maxRight[i]);
        }

        for (int n : maxLeft) cout << n << endl;
        cout << "-----------------" << endl;
        for (int n : maxRight) cout << n << endl;
        cout << "-----------------" << endl;
        for (int n : minLR) cout << n << endl;

        for (int i = 0; i < height.size(); i++)
        {
            water += max(0, minLR[i] - height[i]);
        }

        return water;
    }
};
