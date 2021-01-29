/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if (!root)
        {
            return pre;
        }

        stack<TreeNode *> open;
        vector<TreeNode *> close;

        auto is_visited = [&] (TreeNode * node) -> bool {
            for (const auto cn : close)
            {
                if (cn == node)
                {
                    return true;
                }
            }
            return false;
        };

        open.push(root);
        while(!open.empty())
        {
            TreeNode *top = open.top();
            if (!is_visited(top))
            {
                close.emplace_back(top);
                pre.emplace_back(top->val);
            }
            if (top->left && !is_visited(top->left))
            {
                open.push(top->left);
            }
            else if (top->right && !is_visited(top->right))
            {
                open.push(top->right);
            }
            else
            {
                open.pop();
            }
        }

        return pre;
    }
};
// @lc code=end

