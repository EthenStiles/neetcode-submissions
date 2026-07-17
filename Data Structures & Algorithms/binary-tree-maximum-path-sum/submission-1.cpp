/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root)
    {
        if (!root) return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        leftSum = max(leftSum, 0);
        rightSum = max(rightSum, 0);
        res = max(res, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }
};
