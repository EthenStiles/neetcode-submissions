class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> res;

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int small = numbers[left];
            int big = numbers[right];

            if (small + big == target) return {left + 1, right + 1};
            else if (small + big > target) right--;
            else left++;
        }

        return {};

    }
};
