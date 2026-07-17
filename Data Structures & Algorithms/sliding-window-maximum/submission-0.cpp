class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> res;

        //cout << nums.size() - k + 1 << endl;

        for (int left = 0; left < nums.size() - k + 1; left++)
        {
            int maxElt = INT_MIN;

            for (int right = 0; right < k; right++)
            {
                //cout << nums[left + right] << " ";
                maxElt = max(maxElt, nums[left + right]);
            }

            //cout << endl;
            res.push_back(maxElt);   
        }
        
        
        return res;   
    }
};
