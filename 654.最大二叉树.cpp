/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

private:
    TreeNode* build(vector<int> &nums, int s, int e)
    {
        if (s >= e) return nullptr;

        int max_num = INT_MIN;
        int max_pos = s;
        for (int i = s; i < e; i++)
        {
            if (nums[i] > max_num)
            {
                max_num = nums[i];
                max_pos = i;
            }
        }
        TreeNode* node = new TreeNode(max_num);
        node->left = build(nums, s, max_pos);
        node->right = build(nums, max_pos + 1, e);

        return node;
    }
};
// @lc code=end

