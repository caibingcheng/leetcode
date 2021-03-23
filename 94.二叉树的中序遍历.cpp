/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        mfs(result, root);

        return result;
    }

private:
    void mfs(vector<int> &result, TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            result.emplace_back(root->val);
            return;
        }

        mfs(result, root->left);
        result.emplace_back(root->val);
        mfs(result, root->right);
    }
};
// @lc code=end

