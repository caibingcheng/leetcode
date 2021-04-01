/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode *root, int k)
    {
        int result = 0;
        search(result, root, k);

        return result;
    }

private:
    void search(int &result, TreeNode *root, int &k)
    {
        if (root == nullptr || k <= 0)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (--k >= 0)
            {
                result = root->val;
            }
            return;
        }

        search(result, root->left, k);
        if (--k >= 0)
        {
            result = root->val;
        }
        search(result, root->right, k);
    }
};
// @lc code=end
