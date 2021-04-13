/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode *> path_p, path_q;


    }
private:
    void findPath(stack<TreeNode *> result, TreeNode *root, TreeNode *target) {
        if (root == NULL)
            return;
        if (root->val == target->val)
        {
            result.emplace(root);
            return;
        }
        result.emplace(root);
        findPath(result, root->left, target);
        findPath(result, root->right, target);
    }
};
// @lc code=end

