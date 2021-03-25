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
        if (root == nullptr)
        {
            return result;
        }

        stack<TreeNode *> right;
        stack<TreeNode *> left;

        right.push(root);
        bool sign = true;
        while (!right.empty() || !left.empty())
        {
            vector<int> line;
            while(!right.empty())
            {
                TreeNode *n = right.top();
                right.pop();

                line.push_back(n->val);
                if (n->left)
                    left.push(n->left);
                if (n->right)
                    left.push(n->right);
            }
            if (!line.empty())
            {
                result.push_back(line);
            }

            line.clear();
            while(!left.empty())
            {
                TreeNode *n = left.top();
                left.pop();

                line.push_back(n->val);
                if (n->right)
                    right.push(n->right);
                if (n->left)
                    right.push(n->left);
            }
            if (!line.empty())
            {
                result.push_back(line);
            }
        }

        return result;
    }
};
// @lc code=end
