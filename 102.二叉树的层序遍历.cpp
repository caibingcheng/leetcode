/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }

        vector<TreeNode*> parent;
        vector<TreeNode*> son;

        son.push_back(root);
        while(!son.empty())
        {
            vector<int> line;
            parent.clear();
            for (auto& n : son)
            {
                line.push_back(n->val);
                if (n->left)
                    parent.push_back(n->left);
                if (n->right)
                    parent.push_back(n->right);
            }
            son.clear();
            son = parent;
            result.push_back(line);
        }

        return result;
    }
};
// @lc code=end

