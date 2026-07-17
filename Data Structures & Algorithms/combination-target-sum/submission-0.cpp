class Solution {
public:
    vector<int> candidate;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
    
        dfs(nums, target, 0, 0); 
        return res;
    }

    void dfs(vector<int>& nums, int target, int sum, int start)
    {
        if (sum > target) return;

        if (sum == target)
        {
            res.push_back(candidate);
            return;
        } 

        for (int i = start; i < nums.size(); i++)
        {
            candidate.push_back(nums[i]);
            dfs(nums, target, sum + nums[i], i);
            candidate.pop_back();
        }
    }
};
