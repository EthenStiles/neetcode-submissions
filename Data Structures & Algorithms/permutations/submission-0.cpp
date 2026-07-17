class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> chosen(nums.size(), false);
        dfs(nums, chosen);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool> chosen)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!chosen[i])
            {
                curr.push_back(nums[i]);
                chosen[i] = true;

                dfs(nums, chosen);
                
                curr.pop_back();
                chosen[i] = false;
            }  
        } 
    }
};
