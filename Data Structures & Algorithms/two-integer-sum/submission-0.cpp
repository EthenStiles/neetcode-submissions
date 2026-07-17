class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];

            if (m.contains(target - num) && m[target - num] < i) return {m[target - num], i};
            
            else m[num] = i;
        }

        return {};
    }
};
