class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int i)
    {
        //base case
        if (i == nums.size())
        {
            res.push_back(curr);
            return;
        }

        //recursive case
        curr.push_back(nums[i]);
        dfs(nums, i + 1);
        curr.pop_back();
        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        dfs(nums, i + 1);
    }
};
