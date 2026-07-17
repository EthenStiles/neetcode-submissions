class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.size() == 2) return min(nums[0], nums[1]);
        
        int right = nums.size() - 1;
        int left = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            bool leftMostIsMin = mid == 0 && nums[mid + 1] > nums[mid];
            bool rightMostIsMin = mid == nums.size() - 1 && nums[mid - 1] > nums[mid];
            bool centerIsMin = nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1];

            if (leftMostIsMin || rightMostIsMin || centerIsMin) return nums[mid];

            else if (nums[mid] > nums[right]) left = mid + 1;

            //nums[left] > nums[right]
            else right = mid - 1; 
        }

        return 1001;   
    }
};
