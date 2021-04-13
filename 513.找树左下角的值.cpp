/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        stack<TreeNode *>open;
        list<TreeNode *>close;

        open.emplace(root);

        int result;
        while (!open.empty()) {
            while(!open.empty())
            {
                TreeNode* node = open.top();
                open.pop();
                result = node->val;
                close.emplace_front(node);
            }
            for (auto &node : close)
            {
                if (node->left)
                    open.emplace(node->left);
                if (node->right)
                    open.emplace(node->right);
            }
            close.clear();
        }

        return result;
    }
};
// @lc code=end

