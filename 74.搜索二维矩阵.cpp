/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
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

        int start = 0;
        int end = rows * cols - 1;

        auto get_pos = [&] (const int& index) {
            int r = index / cols;
            int c = index % cols;
            return make_pair(r, c);
        };

        while(start <= end){
            int mid = (start + end) >> 1;
            auto pos = get_pos(mid);

            if (target < matrix[pos.first][pos.second])
            {
                end = mid - 1;
            }
            else if (target > matrix[pos.first][pos.second])
            {
                start = mid + 1;
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

