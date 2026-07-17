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
    vector<int> leftTreeVals;
    vector<int> rightTreeVals;
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        leftDfs(p);
        rightDfs(q);
        
        while (!leftTreeVals.empty() && !rightTreeVals.empty())
        {
            if (leftTreeVals.back() != rightTreeVals.back()) return false;

            leftTreeVals.pop_back();
            rightTreeVals.pop_back();
        }

        if (!leftTreeVals.empty() && rightTreeVals.empty()) return false;
        if (leftTreeVals.empty() && !rightTreeVals.empty()) return false;

        return true;
    }

    void leftDfs(TreeNode* root)
    {
        if (!root)
        {
            leftTreeVals.push_back(-101);
            return;
        }

        leftTreeVals.push_back(root->val);
        leftDfs(root->left);
        leftDfs(root->right);

    }

    void rightDfs(TreeNode* root)
    {
        if (!root)
        {
            rightTreeVals.push_back(-101);
            return;
        }

        rightTreeVals.push_back(root->val);
        rightDfs(root->left);
        rightDfs(root->right);

    }
};
