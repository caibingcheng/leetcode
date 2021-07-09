/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (auto &line : grid)
        {
            if (line[0] != 1)
            {
                for(auto &n : line)
                    n ^= 1;
            }
        }

        int h = grid.size();
        int w = grid[0].size();
        int half = h >> 1;
        for(int i = 1; i < w; i++)
        {
            int cnt = 0;
            for(int j = 0; j < h; j++)
            {
                cnt += grid[j][i];
            }
            if (cnt <= half)
            {
                for(int j = 0; j < h; j++)
                {
                    grid[j][i] ^= 1;
                }
            }
        }

        int result = 0;
        for (auto &line : grid)
        {
            int p = w;
            for(auto &n : line)
            {
                result += n * (1 << (--p));
            }
        }

        return result;
    }
};
// @lc code=end

