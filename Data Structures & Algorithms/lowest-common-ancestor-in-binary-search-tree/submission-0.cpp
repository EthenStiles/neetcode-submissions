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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) return nullptr;

        if ((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val)) return root;

        if (root->val == p->val) return root;
        if (root->val == q->val) return root;

        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);

        if (!leftRes) return rightRes;
        return leftRes;
    }
};
