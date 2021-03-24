/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        TreeNode *pl = root->left;
        TreeNode *pr = root->right;

        return same(pl, pr);
    }

private:
    bool same(TreeNode *pl, TreeNode *pr)
    {
        if (!pl && pl == pr) return true;
        if (!pl || !pr) return false;

        return same(pl->left, pr->right) && same(pl->right, pr->left) && (pl->val == pr->val);
    }
};
// @lc code=end

