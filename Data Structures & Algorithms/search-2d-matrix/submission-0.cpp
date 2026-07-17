class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for (auto vec : matrix)
        {
            int left = 0;
            int right = vec.size() - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if (vec[mid] > target) right = mid - 1;
                else if (vec[mid] < target) left = mid + 1;
                else return true;
            }

        }

        return false;
    }
};
