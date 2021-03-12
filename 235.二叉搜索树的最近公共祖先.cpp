/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *head = root;

        while (head)
        {
            if ((p->val < head->val) && (q->val < head->val))
            {
                head = head->left;
            }
            else if ((p->val > head->val) && (q->val > head->val))
            {
                head = head->right;
            }
            else
            {
                return head;
            }
        }

        return nullptr;
    }
};
// @lc code=end
