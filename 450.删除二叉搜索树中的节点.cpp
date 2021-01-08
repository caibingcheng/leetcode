/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cp = search(root, key);

        if (!cp->left && !cp->right)
        {
            setp(cp, nullptr);
            delete cp;
        }
        else if (cp->left && !cp->right)
        {
            setp(cp, cp->left);
            delete cp;
        }
        else if (cp->right)
        {
            TreeNode *rmin = rightmin(cp->right);
            setp(cp, rmin);
            rmin->left = cp->left;
            rmin->right = cp->right;
            delete cp;
        }

        return root;
    }

private:
    TreeNode* parent = nullptr;

    void setp(TreeNode* cp, TreeNode* v)
    {
        if (parent->left == cp)
        {
            parent->left = v;
        }
        if (parent->right == cp)
        {
            parent->right = v;
        }
    }

    TreeNode* search(TreeNode* root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val == key)
            return root;

        parent = root;
        if (key < root->val)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }

    TreeNode *rightmin(TreeNode *root)
    {
        if (!root)
            return nullptr;

        if (root->left)
        {
            if (!root->left->left && !root->left->right)
            {
                TreeNode *rr = root->left;
                root->left = nullptr;
                return rr;
            }
            else
            {
                if (root->left->left)
                {
                    return rightmin(root->left->left);
                }
                else if(root->left->right)
                {
                    return rightmin(root->left->right);
                }
            }
        }

        return rightmin(root->right);
    }
};
// @lc code=end

