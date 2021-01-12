/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto min = [](const int &a, const int &b){
            return a < b ? a : b;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = INT_MAX, left = INT_MAX;
                if (i - 1 >= 0)
                {
                    up = grid[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    left = grid[i][j - 1];
                }
                if (up != INT_MAX || left != INT_MAX)
                    grid[i][j] += min(up, left);
            }
        }

        return grid[m - 1][n - 1];
    }
};
// @lc code=end

