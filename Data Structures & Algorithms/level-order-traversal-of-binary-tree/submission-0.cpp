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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;

        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++)
            {
                root = q.front();
                q.pop();
                level.push_back(root->val);

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            
            res.push_back(level);
        }

        return res;
    }
};
