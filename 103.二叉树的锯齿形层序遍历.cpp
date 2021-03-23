/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        vector<TreeNode *> open;
        vector<TreeNode *> close;

        if (root == nullptr)
        {
            return result;
        }

        open.emplace_back(root);
        bool sign = true;
        while (!open.empty())
        {
            vector<int> each;
            for (auto &n : open)
            {
                each.emplace_back(n->val);
                close.emplace_back(n);
            }
            open.clear();
            result.emplace_back(each);
            for (auto &n : close)
            {
                if (sign)
                {
                    if (n->right)
                        open.emplace_back(n->right);
                    if (n->left)
                        open.emplace_back(n->left);
                }
                else
                {
                    if (n->left)
                        open.emplace_back(n->left);
                    if (n->right)
                        open.emplace_back(n->right);
                }
            }
            close.clear();
            sign = !sign;
        }

        return result;
    }
};
// @lc code=end
