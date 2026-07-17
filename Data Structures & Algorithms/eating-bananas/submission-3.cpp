class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int minN = INT_MAX;
        int maxN = INT_MIN;
        
        for (int n : piles)
        {
            minN = min(minN, n);
            maxN = max(maxN, n);
        }

        int res = maxN;
        int left = 1;
        int right = maxN;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            int hours = 0;
            for (int pile : piles)
            {
                hours += (pile + mid - 1) / mid;
            }

            if (hours > h)
            {
                //we need to eat more bananas per hour
                left = mid + 1;
            }

            else if (hours <= h)
            {
                //we can eat less bananas per hour to see if we can still achieve the goal within the time limit
                res = min(res, mid);
                right = mid - 1;
            }
        }

        return res;
    }
};
