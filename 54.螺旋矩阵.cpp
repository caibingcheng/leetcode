/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> mps;
        vector<int> result;
        int max_x = matrix[0].size();
        int max_y = matrix.size();
        int pos_x = 0;
        int pos_y = 0;
        int count = max_x * max_y;

        for(int i = 0; i < max_y; i++)
        {
            vector<bool> line(max_x, false);
            mps.push_back(line);
        }

        auto is_visited = [&] () {
            return pos_x >= max_x || pos_y >= max_y || mps[pos_y][pos_x];
        };
        auto setmps = [&] () {
            mps[pos_y][pos_x] = true;
        };
        auto setresult = [&] () {
            count--;
            result.push_back(matrix[pos_y][pos_x]);
        };

        using GOFUNC = function<void(void)>;
        GOFUNC right = [&] () {
            pos_x++;
        };
        GOFUNC left = [&] () {
            pos_x--;
        };
        GOFUNC down = [&] () {
            pos_y++;
        };
        GOFUNC up = [&] () {
            pos_y--;
        };

        vector<pair<GOFUNC, GOFUNC>> fvec {
            {right, left},
            {down, up},
            {left, right},
            {up, down},
        };

        auto go = [&] (auto &pfunc) {
            do
            {
                setmps();
                setresult();
                pfunc.first();
            } while (!is_visited());
            pfunc.second();
        };

        int fidx = 0;
        while(count > 0)
        {
            fidx %= 4;
            go(fvec[fidx++]);
        }

        return result;
    }
};
// @lc code=end

