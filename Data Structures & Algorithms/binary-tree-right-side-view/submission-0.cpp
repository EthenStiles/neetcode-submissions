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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<int> res;
        
        q.push(root);

        while (!q.empty())
        {
            int qSize = q.size();
            
            for (int i = 0; i < qSize; i++)
            {
                root = q.front();
                q.pop();
                if (i + 1 == qSize) res.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        
       return res; 
    }
};
