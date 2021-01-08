/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (root && !(root->left) && !(root->right))
            return 1;

        if (!root)
            return 0;

        int lmin = minDepth(root->left);
        int rmin = minDepth(root->right);

        if ((lmin <= 0) && (rmin <= 0))
            return 0;
        if (lmin <= 0)
            return rmin + 1;
        if (rmin <= 0)
            return lmin + 1;

        return 1 + min(lmin, rmin);
    }

private:
    int min(const int &a, const int &b){
        return a < b ? a : b;
    }
    int max(const int &a, const int &b){
        return a > b ? a : b;
    }
};
// @lc code=end

