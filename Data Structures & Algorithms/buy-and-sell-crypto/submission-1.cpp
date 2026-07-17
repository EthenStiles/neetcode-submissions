class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;

        vector<int> minLeftVal(prices.size(), -1);

        minLeftVal[0] = 101;
        for (int i = 1; i < prices.size(); i++)
        {
            minLeftVal[i] = min(minLeftVal[i - 1], prices[i - 1]);
        }

        for (int i = 0; i < prices.size(); i++) res = max(res, prices[i] - minLeftVal[i]);
        
        //for (int n : minLeftVal) cout << n << endl;
        
        return res; 
    }
};
