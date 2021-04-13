/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;
        int rows = matrix.size();
        if (rows < 1)
            return result;
        int cols = matrix[0].size();
        pair<int, int> pos {0, cols - 1};

        auto valid_pos = [&] () {
            return pos.first >= 0 && pos.first < rows && pos.second >= 0 && pos.second < cols;
        };

        while(valid_pos()) {
            if (matrix[pos.first][pos.second] > target)
            {
                pos.second--;
            }
            else if (matrix[pos.first][pos.second] < target)
            {
                pos.first++;
            }
            else
            {
                result = true;
                break;
            }
        }

        return result;
    }
};
// @lc code=end

