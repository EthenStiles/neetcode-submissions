class Solution {
public:
    vector<int> candidate;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int sum, int start)
    {
        if (sum == target)
        {
            res.push_back(candidate);
            return;
        }
        
        if (sum > target || start == candidates.size()) return;

        candidate.push_back(candidates[start]);
        dfs(candidates, target, sum + candidates[start], start + 1);
        candidate.pop_back();

        while (start + 1 < candidates.size() && candidates[start] == candidates[start + 1]) start++;
        dfs(candidates, target, sum, start + 1);
    }
};
