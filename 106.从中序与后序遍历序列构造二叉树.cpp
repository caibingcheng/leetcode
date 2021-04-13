/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            mps[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    unordered_map<int, int> mps;

    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe)
    {
        TreeNode *root = nullptr;

        if (is >= ie || ie > inorder.size() || ps >= pe || pe > postorder.size())
        {
            return nullptr;
        }

        root = new TreeNode(postorder[pe - 1]);
        {
            int iis = is, iie = ie, pps = ps, ppe = pe;
            updateLeftPos(inorder, iis, iie, postorder, pps, ppe);
            // cout << "left: " << iis << "," << iie << "," << pps << "," << ppe << endl;
            root->left = build(inorder, iis, iie, postorder, pps, ppe);
        }
        {
            int iis = is, iie = ie, pps = ps, ppe = pe;
            updateRightPos(inorder, iis, iie, postorder, pps, ppe);
            // cout << "right: " << iis << "," << iie << "," << pps << "," << ppe << endl;
            root->right = build(inorder, iis, iie, postorder, pps, ppe);
        }

        return root;
    }

    void updateLeftPos(vector<int>& inorder, int& is, int& ie, vector<int>& postorder, int& ps, int& pe)
    {
        int root = postorder[pe - 1];
        ie = mps[root];
        pe = ie - is + ps;
    }

    void updateRightPos(vector<int>& inorder, int& is, int& ie, vector<int>& postorder, int& ps, int& pe)
    {
        int root = postorder[pe - 1];
        is = mps[root] + 1;
        pe--;
        ps = pe - (ie - is);
    }
};
// @lc code=end

