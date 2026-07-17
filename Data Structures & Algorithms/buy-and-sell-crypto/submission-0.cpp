class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;

        for (int buydate = 0; buydate < prices.size(); buydate++)
        {
            for (int selldate = buydate + 1; selldate < prices.size(); selldate++)
            {
                res = max(res, prices[selldate] - prices[buydate]);
            }
        }
        
        return res; 
    }
};
