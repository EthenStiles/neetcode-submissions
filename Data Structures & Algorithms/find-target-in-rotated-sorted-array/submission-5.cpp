class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;

        int pivotIndex = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            bool isLeftMin = mid == 0 && nums[mid] < nums[mid + 1];
            bool isRightMin = mid == nums.size() - 1 && nums[mid - 1] > nums[mid];
            bool isCenterMin = nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1];
            
            if (nums[mid] == target) return mid;
            if (isLeftMin || isRightMin || isCenterMin)
            {
                pivotIndex = mid;
                break;
            }

            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid - 1;
        }

        left = 0;
        right = nums.size();

        if (pivotIndex == nums.size() - 1 || nums[0] <= target && target <= nums[pivotIndex - 1])
        {
            right = pivotIndex - 1;
        }
        
        else left = pivotIndex;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid;
        }
        
        return -1;
    }
};
