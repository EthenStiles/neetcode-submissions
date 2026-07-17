class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int vecLeft = 0;
        int vecRight = matrix.size() - 1;
        
        while (vecLeft <= vecRight)
        {
            int vecMid = vecLeft + (vecRight - vecLeft) / 2;
            int vecMidFirst = matrix[vecMid][0];
            int vecMidLast = matrix[vecMid][matrix[vecMid].size() - 1];
            
            if (vecMidFirst > target) vecRight = vecMid - 1;
            else if (vecMidLast < target) vecLeft = vecMid + 1;
            else 
            {
                int left = 0;
                int right = matrix[vecMid].size() - 1;

                while (left <= right)
                {
                    int mid = left + (right - left) / 2;

                    if (matrix[vecMid][mid] > target) right = mid - 1;
                    else if (matrix[vecMid][mid] < target) left = mid + 1;
                    else return true;
                }

                return false;
            }
        }
        
        return false;
    }
};
