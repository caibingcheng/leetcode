/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        flip(matrix);
        diag(matrix);
    }

private:
    void flip(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            for (int i = 0; i < n; i++)
            {
                swap(matrix[start][i], matrix[end][i]);
            }
            start++;
            end--;
        }
    }

    void diag(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

