class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res;
        int product = 1;
        int zeroCount = false;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (x != 0) product *= x;
            else zeroCount++;
        } 

        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (x == 0)
            {
                if (zeroCount == 1) res.push_back(product);
                else res.push_back(0);
            } 

            else if (zeroCount) res.push_back(0);
            else res.push_back(product / x);
        }  
       
        return res;
    }
};
